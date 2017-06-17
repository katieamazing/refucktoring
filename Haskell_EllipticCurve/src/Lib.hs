-- Code from http://rosettacode.org/wiki/Elliptic_curve_arithmetic#Haskell

module Lib
    ( Elliptic(..), inv, mult
    ) where

import Data.Monoid

data Elliptic = Elliptic Double Double | Zero
   deriving Show
 
instance Eq Elliptic where
  p == q = dist p q < 1e-14
    where
      dist Zero Zero = 0
      dist Zero p = 1/0
      dist p Zero = 1/0
      dist (Elliptic x1 y1) (Elliptic x2 y2) = (x2-x1)^2 + (y2-y1)^2
 
inv Zero = Zero
inv (Elliptic x y) = Elliptic x (-y)

instance Monoid Elliptic where
  mempty = Zero
 
  mappend Zero p = p
  mappend p Zero = p
  mappend p@(Elliptic x1 y1) q@(Elliptic x2 y2)
    | p == inv q = Zero
    | p == q     = mkElliptic $ 3*x1^2/(2*y1)
    | otherwise  = mkElliptic $ (y2 - y1)/(x2 - x1)
    where
      mkElliptic l = let x = l^2 - x1 - x2
                         y = l*(x1 - x) - y1
                     in Elliptic x y

mult :: Int -> Elliptic -> Elliptic
mult n p
  | n == 0 = Zero
  | n == 1 = p
  | n == 2 = p <> p
  | n < 0  = inv ((-n) `mult` p)
  | even n = 2 `mult` ((n `div` 2) `mult` p)
  | odd n  = p <> (n -1) `mult` p
