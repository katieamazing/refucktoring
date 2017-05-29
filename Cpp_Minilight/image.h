/*------------------------------------------------------------------------------

   MiniLight C++ : minimal global illumination renderer
   Harrison Ainsworth / HXA7241 : 2006-2011, 2013

   http://www.hxa.name/minilight

------------------------------------------------------------------------------*/

#ifndef Image_h
#define Image_h

#include <iosfwd>
#include <vector>

#include "vector3f.h"
#include "hxa7241_minilight.h"

namespace hxa7241_minilight
{

/**
 * Pixel sheet with simple tone-mapping and file formatting.<br/><br/>
 *
 * Uses PPM image format:
 * <cite>http://netpbm.sourceforge.net/doc/ppm.html</cite><br/><br/>
 *
 * Uses Ward simple tonemapper:
 * <cite>'A Contrast Based Scalefactor For Luminance Display'
 * Ward;
 * Graphics Gems 4, AP 1994.</cite><br/><br/>
 *
 * Uses RGBE image format:
 * <cite>http://radsite.lbl.gov/radiance/refer/filefmts.pdf</cite>
 * <cite>'Real Pixels' Ward; Graphics Gems 2, AP 1991;</cite><br/><br/>
 *
 * @invariants
 * * width_m  >= 1 and <= DIMENSION_MAX
 * * height_m >= 1 and <= DIMENSION_MAX
 * * pixels_m.size() == (width_m * height_m)
 */
class Image
{
 public:
  explicit Image( std::istream& );
  
  void addToPixel( int32 x, int32 y, const Vector3f& radiance );
  
  int32 getWidth() const;
  int32 getHeight() const;
  
  void getFormatted( std::ostream& out, int32 iteration ) const;
  
  static int32 DIMENSION_MAX();
  
 protected:
  static real64 calculateToneMapping( const std::vector<Vector3f>& pixels, real64 divider );

 private:
  int32 width_m;
  int32 height_m;
  std::vector<Vector3f> pixels_m;
};

}//namespace

#endif//Image_h
