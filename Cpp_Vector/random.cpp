/*------------------------------------------------------------------------------

   MiniLight C++ : minimal global illumination renderer
   Harrison Ainsworth / HXA7241 : 2006-2011, 2013

   http://www.hxa.name/minilight

------------------------------------------------------------------------------*/

#include <time.h>
#include <stdio.h>

#include "random.h"

using namespace hxa7241_general;

/// constants ------------------------------------------------------------------

namespace
{
   // default seed
   const int32u SEED = 987654321;
}

Random::Random()
{
   /* *** VERY IMPORTANT ***
      The initial seeds z1, z2, z3, z4  MUST be larger
      than 1, 7, 15, and 127 respectively. */

   z_m[0] = z_m[1] = z_m[2] = z_m[3] = SEED;
}

/// queries --------------------------------------------------------------------

int32u Random::getInt32u() const
{
   z_m[0] = ((z_m[0] & 0xFFFFFFFEu) << 18) ^ (((z_m[0] <<  6) ^ z_m[0]) >> 13);
   z_m[1] = ((z_m[1] & 0xFFFFFFF8u) <<  2) ^ (((z_m[1] <<  2) ^ z_m[1]) >> 27);
   z_m[2] = ((z_m[2] & 0xFFFFFFF0u) <<  7) ^ (((z_m[2] << 13) ^ z_m[2]) >> 21);
   z_m[3] = ((z_m[3] & 0xFFFFFF80u) << 13) ^ (((z_m[3] <<  3) ^ z_m[3]) >> 12);

   return z_m[0] ^ z_m[1] ^ z_m[2] ^ z_m[3];
}

real64 Random::getReal64() const
{
   return static_cast<real64>(static_cast<int32>(getInt32u())) *
      (1.0 / 4294967296.0) + 0.5 +
      static_cast<real64>(static_cast<int32>(getInt32u() & 0x001FFFFFu)) *
      (1.0 / 9007199254740992.0);
}
