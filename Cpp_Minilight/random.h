/*------------------------------------------------------------------------------

   MiniLight C++ : minimal global illumination renderer
   Harrison Ainsworth / HXA7241 : 2006-2011, 2013

   http://www.hxa.name/minilight

------------------------------------------------------------------------------*/

#ifndef Random_h
#define Random_h

#include "hxa7241_general.h"

namespace hxa7241_general
{

/**
 * Simple, fast, good random number generator.<br/><br/>
 *
 * @implementation
 *
 * 'Maximally Equidistributed Combined Tausworthe Generators'; L'Ecuyer; 1996.
 * http://www.iro.umontreal.ca/~lecuyer/myftp/papers/tausme2.ps
 * http://www.iro.umontreal.ca/~simardr/rng/lfsr113.c
 *
 * 'Conversion of High-Period Random Numbers to Floating Point'; Doornik; 2006.
 * http://www.doornik.com/research/randomdouble.pdf
 */
class Random
{
 public:
  Random();

  int32u getInt32u() const;
  
  /**
   * Souble precision, [0,1) interval (never returns 1).
   */
  real64 getReal64() const;

 private:
  mutable int32u z_m[4];
};

}//namespace

#endif//Random_h
