/*------------------------------------------------------------------------------

   MiniLight C++ : minimal global illumination renderer
   Harrison Ainsworth / HXA7241 : 2006-2011, 2013

   http://www.hxa.name/minilight

------------------------------------------------------------------------------*/


#include <math.h>
#include <iostream>

#include "vector3f.h"

using namespace hxa7241_graphics;

Vector3f::Vector3f()
{
   xyz_m[0] = 0.0;
   xyz_m[1] = 0.0;
   xyz_m[2] = 0.0;
}


Vector3f::Vector3f
(
   const real64 x,
   const real64 y,
   const real64 z
)
{
   xyz_m[0] = x;
   xyz_m[1] = y;
   xyz_m[2] = z;
}

real64 Vector3f::dot
(
   const Vector3f& v
) const
{
   return (xyz_m[0] * v.xyz_m[0]) +
          (xyz_m[1] * v.xyz_m[1]) +
          (xyz_m[2] * v.xyz_m[2]);
}

Vector3f Vector3f::operator-() const
{
   return Vector3f( -xyz_m[0], -xyz_m[1], -xyz_m[2] );
}


Vector3f Vector3f::unitize() const
{
   // Zero vectors, and vectors of near zero magnitude, produce zero length,
   // and (since 1 / 0 is conditioned to 0) ultimately a zero vector result.
   // Vectors of extremely large magnitude produce +infinity length, and (since
   // 1 / inf is 0) ultimately a zero vector result.
   // (Perhaps zero vectors should produce infinite results, but pragmatically,
   // zeros are probably easier to handle than infinities.)

   const real64 length        = ::sqrt( dot( *this ) );
   const real64 oneOverLength = length != 0.0 ? 1.0 / length : 0.0;

   return Vector3f( *this * oneOverLength );
}


Vector3f Vector3f::cross
(
   const Vector3f& v
) const
{
   return Vector3f( (xyz_m[1] * v.xyz_m[2]) - (xyz_m[2] * v.xyz_m[1]),
                    (xyz_m[2] * v.xyz_m[0]) - (xyz_m[0] * v.xyz_m[2]),
                    (xyz_m[0] * v.xyz_m[1]) - (xyz_m[1] * v.xyz_m[0]) );
}


Vector3f Vector3f::operator+
(
   const Vector3f& v
) const
{
   return Vector3f( xyz_m[0] + v.xyz_m[0],
                    xyz_m[1] + v.xyz_m[1],
                    xyz_m[2] + v.xyz_m[2] );
}


Vector3f Vector3f::operator-
(
   const Vector3f& v
) const
{
   return Vector3f( xyz_m[0] - v.xyz_m[0],
                    xyz_m[1] - v.xyz_m[1],
                    xyz_m[2] - v.xyz_m[2] );
}


Vector3f Vector3f::operator*
(
   const Vector3f& v
) const
{
   return Vector3f( xyz_m[0] * v.xyz_m[0],
                    xyz_m[1] * v.xyz_m[1],
                    xyz_m[2] * v.xyz_m[2] );
}

Vector3f Vector3f::operator*
(
   const real64 f
) const
{
   return Vector3f( xyz_m[0] * f,
                    xyz_m[1] * f,
                    xyz_m[2] * f );
}


Vector3f Vector3f::operator/
(
   const real64 f
) const
{
   const real64 oneOverF = 1.0 / f;

   return Vector3f( xyz_m[0] * oneOverF,
                    xyz_m[1] * oneOverF,
                    xyz_m[2] * oneOverF );
}

bool Vector3f::isZero() const
{
   return bool( (xyz_m[0] == 0.0) & (xyz_m[1] == 0.0) & (xyz_m[2] == 0.0) );
}

Vector3f Vector3f::getClamped
(
   const Vector3f& min,
   const Vector3f& max
) const
{
   Vector3f r( *this );

   for( int i = 3;  i-- > 0; )
   {
      r.xyz_m[i] = r.xyz_m[i] >= min.xyz_m[i] ? r.xyz_m[i] : min.xyz_m[i];
      r.xyz_m[i] = r.xyz_m[i] <= max.xyz_m[i] ? r.xyz_m[i] : max.xyz_m[i];
   }

   return r;
}

const Vector3f& Vector3f::ZERO()
{
   static const Vector3f k( 0.0, 0.0, 0.0 );
   return k;
}

const Vector3f& Vector3f::ONE()
{
   static const Vector3f k( 1.0, 1.0, 1.0 );
   return k;
}

const Vector3f& Vector3f::MIN()
{
   static const Vector3f k( REAL64_MIN_NEG, REAL64_MIN_NEG, REAL64_MIN_NEG );
   return k;
}


const Vector3f& Vector3f::MAX()
{
   static const Vector3f k( REAL64_MAX, REAL64_MAX, REAL64_MAX );
   return k;
}

std::istream& hxa7241_graphics::operator>>
(
   std::istream& in,
   Vector3f&     obj
)
{
   char   c;
   real64 xyz[3];

   in >> c >> xyz[0] >> xyz[1] >> xyz[2] >> c;
   obj = Vector3f( xyz[0], xyz[1], xyz[2] );

   return in;
}
