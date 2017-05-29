/*------------------------------------------------------------------------------

   MiniLight C++ : minimal global illumination renderer
   Harrison Ainsworth / HXA7241 : 2006-2011, 2013

   http://www.hxa.name/minilight

------------------------------------------------------------------------------*/


#include <math.h>
#include <iostream>

#include "vector3f.h"


using namespace hxa7241_graphics;




/// standard object services ---------------------------------------------------

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


//Vector3f::Vector3f
//(
//   const real64 xyz[3]
//)
//{
//   xyz_m[0] = xyz[0];
//   xyz_m[1] = xyz[1];
//   xyz_m[2] = xyz[2];
//}


//Vector3f::Vector3f
//(
//   const Vector3f& other
//)
//{
//   xyz_m[0] = other.xyz_m[0];
//   xyz_m[1] = other.xyz_m[1];
//   xyz_m[2] = other.xyz_m[2];
//}
//
//
//Vector3f& Vector3f::operator=
//(
//   const Vector3f& other
//)
//{
//   if( &other != this )
//   {
//      xyz_m[0] = other.xyz_m[0];
//      xyz_m[1] = other.xyz_m[1];
//      xyz_m[2] = other.xyz_m[2];
//   }
//
//   return *this;
//}




/// commands -------------------------------------------------------------------

/*Vector3f& Vector3f::set
(
   const real64 x,
   const real64 y,
   const real64 z
)
{
   xyz_m[0] = x;
   xyz_m[1] = y;
   xyz_m[2] = z;

   return *this;
}


Vector3f& Vector3f::set
(
   const real64 xyz[3]
)
{
   xyz_m[0] = xyz[0];
   xyz_m[1] = xyz[1];
   xyz_m[2] = xyz[2];

   return *this;
}*/


/*Vector3f& Vector3f::negateEq()
{
   xyz_m[0] = -xyz_m[0];
   xyz_m[1] = -xyz_m[1];
   xyz_m[2] = -xyz_m[2];

   return *this;
}


Vector3f& Vector3f::absEq()
{
   if( xyz_m[0] < 0.0 )
   {
      xyz_m[0] = -xyz_m[0];
   }
   if( xyz_m[1] < 0.0 )
   {
      xyz_m[1] = -xyz_m[1];
   }
   if( xyz_m[2] < 0.0 )
   {
      xyz_m[2] = -xyz_m[2];
   }

   return *this;
}


Vector3f& Vector3f::unitizeEq()
{
   const real64 length        = ::sqrt( dot( *this ) );
   const real64 oneOverLength = length != 0.0 ? 1.0 / length : 0.0;

   operator*=( oneOverLength );

   return *this;
}


Vector3f& Vector3f::crossEq
(
   const Vector3f& v
)
{
   const real64 x = (xyz_m[1] * v.xyz_m[2]) - (xyz_m[2] * v.xyz_m[1]);
   const real64 y = (xyz_m[2] * v.xyz_m[0]) - (xyz_m[0] * v.xyz_m[2]);
   const real64 z = (xyz_m[0] * v.xyz_m[1]) - (xyz_m[1] * v.xyz_m[0]);

   xyz_m[0] = x;
   xyz_m[1] = y;
   xyz_m[2] = z;

   return *this;
}


Vector3f& Vector3f::operator+=
(
   const Vector3f& v
)
{
   xyz_m[0] += v.xyz_m[0];
   xyz_m[1] += v.xyz_m[1];
   xyz_m[2] += v.xyz_m[2];

   return *this;
}


Vector3f& Vector3f::operator-=
(
   const Vector3f& v
)
{
   xyz_m[0] -= v.xyz_m[0];
   xyz_m[1] -= v.xyz_m[1];
   xyz_m[2] -= v.xyz_m[2];

   return *this;
}


Vector3f& Vector3f::operator*=
(
   const Vector3f& v
)
{
   xyz_m[0] *= v.xyz_m[0];
   xyz_m[1] *= v.xyz_m[1];
   xyz_m[2] *= v.xyz_m[2];

   return *this;
}


Vector3f& Vector3f::operator/=
(
   const Vector3f& v
)
{
   xyz_m[0] /= v.xyz_m[0];
   xyz_m[1] /= v.xyz_m[1];
   xyz_m[2] /= v.xyz_m[2];

   return *this;
}


Vector3f& Vector3f::operator*=
(
   const real64 f
)
{
   xyz_m[0] *= f;
   xyz_m[1] *= f;
   xyz_m[2] *= f;

   return *this;
}


Vector3f& Vector3f::operator/=
(
   const real64 f
)
{
   const real64 oneOverF = 1.0 / f;

   xyz_m[0] *= oneOverF;
   xyz_m[1] *= oneOverF;
   xyz_m[2] *= oneOverF;

   return *this;
}*/


/*Vector3f& Vector3f::clampMin
(
   const Vector3f& min
)
{
   if( xyz_m[0] < min.xyz_m[0] )
   {
      xyz_m[0] = min.xyz_m[0];
   }
   if( xyz_m[1] < min.xyz_m[1] )
   {
      xyz_m[1] = min.xyz_m[1];
   }
   if( xyz_m[2] < min.xyz_m[2] )
   {
      xyz_m[2] = min.xyz_m[2];
   }

   return *this;
}


Vector3f& Vector3f::clampMax
(
   const Vector3f& max
)
{
   if( xyz_m[0] > max.xyz_m[0] )
   {
      xyz_m[0] = max.xyz_m[0];
   }
   if( xyz_m[1] > max.xyz_m[1] )
   {
      xyz_m[1] = max.xyz_m[1];
   }
   if( xyz_m[2] > max.xyz_m[2] )
   {
      xyz_m[2] = max.xyz_m[2];
   }

   return *this;
}


Vector3f& Vector3f::clamp
(
   const Vector3f& min,
   const Vector3f& max
)
{
   if( xyz_m[0] > max.xyz_m[0] )
      xyz_m[0] = max.xyz_m[0];
   else
   if( xyz_m[0] < min.xyz_m[0] )
      xyz_m[0] = min.xyz_m[0];

   if( xyz_m[1] > max.xyz_m[1] )
      xyz_m[1] = max.xyz_m[1];
   else
   if( xyz_m[1] < min.xyz_m[1] )
      xyz_m[1] = min.xyz_m[1];

   if( xyz_m[2] > max.xyz_m[2] )
      xyz_m[2] = max.xyz_m[2];
   else
   if( xyz_m[2] < min.xyz_m[2] )
      xyz_m[2] = min.xyz_m[2];

   return *this;
}


// [0,1)  0 to almost 1
Vector3f& Vector3f::clamp01()
{
   if( xyz_m[0] >= 1.0 )
      xyz_m[0]  = REAL64_ALMOST_ONE;
   else
   if( xyz_m[0] < 0.0 )
      xyz_m[0] = 0.0;

   if( xyz_m[1] >= 1.0 )
      xyz_m[1]  = REAL64_ALMOST_ONE;
   else
   if( xyz_m[1] < 0.0 )
      xyz_m[1] = 0.0;

   if( xyz_m[2] >= 1.0 )
      xyz_m[2]  = REAL64_ALMOST_ONE;
   else
   if( xyz_m[2] < 0.0 )
      xyz_m[2] = 0.0;

   return *this;
}*/




/// queries --------------------------------------------------------------------

/*void Vector3f::get
(
   real64& x_o,
   real64& y_o,
   real64& z_o
) const
{
   x_o = xyz_m[0];
   y_o = xyz_m[1];
   z_o = xyz_m[2];
}


void Vector3f::get
(
   real64 xyz[3]
) const
{
   xyz[0] = xyz_m[0];
   xyz[1] = xyz_m[1];
   xyz[2] = xyz_m[2];
}*/


/*real64 Vector3f::sum() const
{
   return xyz_m[0] + xyz_m[1] + xyz_m[2];
}


real64 Vector3f::average() const
{
   static const real64 ONE_OVER_3 = 1.0 / 3.0;

   return (xyz_m[0] + xyz_m[1] + xyz_m[2]) * ONE_OVER_3;
}


real64 Vector3f::smallest() const
{
   real64 smallest = xyz_m[0] <= xyz_m[1] ? xyz_m[0] : xyz_m[1];
   smallest        = smallest <= xyz_m[2] ? smallest : xyz_m[2];

   return smallest;
}


real64 Vector3f::largest() const
{
   real64 largest = xyz_m[0] >= xyz_m[1] ? xyz_m[0] : xyz_m[1];
   largest        = largest  >= xyz_m[2] ? largest  : xyz_m[2];

   return largest;
}*/


/*real64 Vector3f::length() const
{
   return ::sqrt( (xyz_m[0] * xyz_m[0]) +
                  (xyz_m[1] * xyz_m[1]) +
                  (xyz_m[2] * xyz_m[2]) );
}*/


real64 Vector3f::dot
(
   const Vector3f& v
) const
{
   return (xyz_m[0] * v.xyz_m[0]) +
          (xyz_m[1] * v.xyz_m[1]) +
          (xyz_m[2] * v.xyz_m[2]);
}


/*real64 Vector3f::distance
(
   const Vector3f& v
) const
{
   const real64 xDif = xyz_m[0] - v.xyz_m[0];
   const real64 yDif = xyz_m[1] - v.xyz_m[1];
   const real64 zDif = xyz_m[2] - v.xyz_m[2];

   return ::sqrt( (xDif * xDif) +
                  (yDif * yDif) +
                  (zDif * zDif) );

   //const Vector3f dif( *this - v );
   //
   //return ::sqrt( dif.dot( dif ) );
}*/


Vector3f Vector3f::operator-() const
{
   return Vector3f( -xyz_m[0], -xyz_m[1], -xyz_m[2] );
}


/*Vector3f Vector3f::abs() const
{
   return Vector3f( xyz_m[0] >= 0.0 ? xyz_m[0] : -xyz_m[0],
                    xyz_m[1] >= 0.0 ? xyz_m[1] : -xyz_m[1],
                    xyz_m[2] >= 0.0 ? xyz_m[2] : -xyz_m[2] );

   //return Vector3f( *this ).absEq();
}*/


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


/*Vector3f Vector3f::operator/
(
   const Vector3f& v
) const
{
   return Vector3f( xyz_m[0] / v.xyz_m[0],
                    xyz_m[1] / v.xyz_m[1],
                    xyz_m[2] / v.xyz_m[2] );
}*/


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


/*bool Vector3f::operator==
(
   const Vector3f& v
) const
{
   return (xyz_m[0] == v.xyz_m[0]) &
          (xyz_m[1] == v.xyz_m[1]) &
          (xyz_m[2] == v.xyz_m[2]);
}


bool Vector3f::operator!=
(
   const Vector3f& v
) const
{
   return (xyz_m[0] != v.xyz_m[0]) |
          (xyz_m[1] != v.xyz_m[1]) |
          (xyz_m[2] != v.xyz_m[2]);
}*/


bool Vector3f::isZero() const
{
   return bool( (xyz_m[0] == 0.0) & (xyz_m[1] == 0.0) & (xyz_m[2] == 0.0) );
}


/*Vector3f Vector3f::sign() const
{
   return compare( Vector3f::ZERO() );
}


Vector3f Vector3f::compare
(
   const Vector3f& v
) const
{
   return Vector3f(
      xyz_m[0] > v.xyz_m[0] ? +1.0 : (xyz_m[0] == v.xyz_m[0] ? 0.0 : -1.0),
      xyz_m[1] > v.xyz_m[1] ? +1.0 : (xyz_m[1] == v.xyz_m[1] ? 0.0 : -1.0),
      xyz_m[2] > v.xyz_m[2] ? +1.0 : (xyz_m[2] == v.xyz_m[2] ? 0.0 : -1.0) );
}


Vector3f Vector3f::equal
(
   const Vector3f& v
) const
{
   return Vector3f( static_cast<real64>(xyz_m[0] == v.xyz_m[0]),
                    static_cast<real64>(xyz_m[1] == v.xyz_m[1]),
                    static_cast<real64>(xyz_m[2] == v.xyz_m[2]) );
}


Vector3f Vector3f::operator>
(
   const Vector3f& v
) const
{
   return Vector3f( static_cast<real64>(xyz_m[0] > v.xyz_m[0]),
                    static_cast<real64>(xyz_m[1] > v.xyz_m[1]),
                    static_cast<real64>(xyz_m[2] > v.xyz_m[2]) );
}


Vector3f Vector3f::operator>=
(
   const Vector3f& v
) const
{
   return Vector3f( static_cast<real64>(xyz_m[0] >= v.xyz_m[0]),
                    static_cast<real64>(xyz_m[1] >= v.xyz_m[1]),
                    static_cast<real64>(xyz_m[2] >= v.xyz_m[2]) );
}


Vector3f Vector3f::operator<
(
   const Vector3f& v
) const
{
   return Vector3f( static_cast<real64>(xyz_m[0] < v.xyz_m[0]),
                    static_cast<real64>(xyz_m[1] < v.xyz_m[1]),
                    static_cast<real64>(xyz_m[2] < v.xyz_m[2]) );
}


Vector3f Vector3f::operator<=
(
   const Vector3f& v
) const
{
   return Vector3f( static_cast<real64>(xyz_m[0] <= v.xyz_m[0]),
                    static_cast<real64>(xyz_m[1] <= v.xyz_m[1]),
                    static_cast<real64>(xyz_m[2] <= v.xyz_m[2]) );
}


void Vector3f::getClamped01
(
   Vector3f& result_o
) const   // [0,1)  0 to almost 1
{
   if( xyz_m[0] >= 1.0 )
      result_o.xyz_m[0] = REAL64_ALMOST_ONE;
   else
   if( xyz_m[0] < 0.0 )
      result_o.xyz_m[0] = 0.0;
   else
      result_o.xyz_m[0] = xyz_m[0];

   if( xyz_m[1] >= 1.0 )
      result_o.xyz_m[1] = REAL64_ALMOST_ONE;
   else
   if( xyz_m[1] < 0.0 )
      result_o.xyz_m[1] = 0.0;
   else
      result_o.xyz_m[1] = xyz_m[1];

   if( xyz_m[2] >= 1.0 )
      result_o.xyz_m[2] = REAL64_ALMOST_ONE;
   else
   if( xyz_m[2] < 0.0 )
      result_o.xyz_m[2] = 0.0;
   else
      result_o.xyz_m[2] = xyz_m[2];

   //result_o = *this;
   //result_o.clamp01();
}*/


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




/// friends --------------------------------------------------------------------

/*Vector3f hxa7241_graphics::operator*
(
   const real64    f,
   const Vector3f& v
)
{
   return Vector3f( f * v.xyz_m[0],
                    f * v.xyz_m[1],
                    f * v.xyz_m[2] );
}




Vector3f hxa7241_graphics::operator/
(
   const real64    f,
   const Vector3f& v
)
{
   return Vector3f( f / v.xyz_m[0],
                    f / v.xyz_m[1],
                    f / v.xyz_m[2] );
}*/




/// constants ------------------------------------------------------------------

const Vector3f& Vector3f::ZERO()
{
   static const Vector3f k( 0.0, 0.0, 0.0 );
   return k;
}


/*const Vector3f& Vector3f::HALF()
{
   static const Vector3f k( 0.5, 0.5, 0.5 );
   return k;
}*/


const Vector3f& Vector3f::ONE()
{
   static const Vector3f k( 1.0, 1.0, 1.0 );
   return k;
}


/*const Vector3f& Vector3f::EPSILON()
{
   static const Vector3f k( REAL64_EPSILON, REAL64_EPSILON, REAL64_EPSILON );
   return k;
}*/


/*const Vector3f& Vector3f::ALMOST_ONE()
{
   static const Vector3f k( REAL64_ALMOST_ONE,
                            REAL64_ALMOST_ONE,
                            REAL64_ALMOST_ONE );
   return k;
}*/


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


/*const Vector3f& Vector3f::SMALL()
{
   static const Vector3f k( REAL64_SMALL, REAL64_SMALL, REAL64_SMALL );
   return k;
}


const Vector3f& Vector3f::LARGE()
{
   static const Vector3f k( REAL64_LARGE, REAL64_LARGE, REAL64_LARGE );
   return k;
}*/


/*const Vector3f& Vector3f::X()
{
   static const Vector3f k( 1.0, 0.0, 0.0 );
   return k;
}


const Vector3f& Vector3f::Y()
{
   static const Vector3f k( 0.0, 1.0, 0.0 );
   return k;
}


const Vector3f& Vector3f::Z()
{
   static const Vector3f k( 0.0, 0.0, 1.0 );
   return k;
}*/




/// streaming ------------------------------------------------------------------

//std::ostream& hxa7241_graphics::operator<<
//(
//   std::ostream&   out,
//   const Vector3f& obj
//)
//{
//   return out << '(' << obj[0] << ' ' << obj[1] << ' ' << obj[2] << ')';
//}


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
