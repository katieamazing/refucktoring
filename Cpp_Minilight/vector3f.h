/*------------------------------------------------------------------------------

   MiniLight C++ : minimal global illumination renderer
   Harrison Ainsworth / HXA7241 : 2006-2011, 2013

   http://www.hxa.name/minilight

------------------------------------------------------------------------------*/

#ifndef Vector3f_h
#define Vector3f_h

#include <iosfwd>
#include "hxa7241_graphics.h"

namespace hxa7241_graphics
{

/**
 * Yes, its the 3D vector class!.<br/><br/>
 *
 * ...mostly the usual sort of stuff.<br/><br/>
 *
 * Constant.
 */
class Vector3f {
 public:
  Vector3f();
  Vector3f( real64 x, real64 y, real64 z );
  real64 operator[]( int ) const;
  real64 dot( const Vector3f& ) const;
  Vector3f operator-() const;
  Vector3f unitize() const;
  Vector3f cross( const Vector3f& ) const;
  Vector3f operator+( const Vector3f& ) const;
  Vector3f operator-( const Vector3f& ) const;
  Vector3f operator*( const Vector3f& ) const;
  Vector3f operator*( real64 ) const;
  Vector3f operator/( real64 ) const;
  bool isZero() const;
  Vector3f getClamped( const Vector3f& min, const Vector3f& max ) const;

  // constants ------------------------------------------------------------------
  static const Vector3f& ZERO();
  static const Vector3f& ONE();
  static const Vector3f& MIN();
  static const Vector3f& MAX();

 private:
   real64 xyz_m[3];
};

std::istream& operator>>( std::istream&, Vector3f& );

inline real64 Vector3f::operator[](const int i) const {
  return xyz_m[i];
}

}//namespace

#endif//Vector3f_h
