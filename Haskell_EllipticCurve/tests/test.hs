-- these tests are drawn from http://rosettacode.org/wiki/Elliptic_curve_arithmetic#Haskell
module Main where

import Control.Monad (guard)
import Data.Monoid

import Test.QuickCheck (quickCheck)
import Test.Tasty

import Test.Tasty.QuickCheck as QC

import Lib

main = defaultMain $ testGroup "Properties" 
         [ QC.testProperty "addition" addition
         , QC.testProperty "associativity" associativity
         , QC.testProperty "commutativity" commutativity
         , QC.testProperty "multiplication (slightly flakey)" multiplication
         ]



-- for given a, b and x returns a point on the positive branch of elliptic curve (if point exists)
elliptic a b Nothing  = Just Zero
elliptic a b (Just x) =
  do let y2 = x**3 + a*x + b
     guard (y2 > 0)
     return $ Elliptic x (sqrt y2)
 
addition a b x1 x2 =
  let p = elliptic a b
      s = p x1 <> p x2
  in (s /= Nothing) ==> (s <> (inv <$> s) == Just Zero)
 
associativity a b x1 x2 x3 =
  let p = elliptic a b
  in (p x1 <> p x2) <> p x3 == p x1 <> (p x2 <> p x3)
 
commutativity a b x1 x2 = 
  let p = elliptic a b
  in p x1 <> p x2 == p x2 <> p x1


mult' :: Int -> Elliptic -> Elliptic
mult' 0 p = Zero
mult' 1 p = p
mult' n p = let a = n `div` 2
                b = n - a
             in mult' a p <> mult' b p

closeElliptics (Elliptic x1 y1) (Elliptic x2 y2) = around1 (x1 / x2) && around1 (y1 / y2)
  where around1 n | n < 0.999 = False
                  | n > 1.001 = False
                  | otherwise = True
closeElliptics Zero Zero = True

multiplication a b x n = (n :: Int) >= 0 && n <= 10 QC.==>
  case elliptic a b x of
    Just e -> closeElliptics (mult' n e) (mult n e)
    _      -> True
