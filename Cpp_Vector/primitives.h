/*------------------------------------------------------------------------------

   MiniLight C++ : minimal global illumination renderer
   Harrison Ainsworth / HXA7241 : 2006-2011, 2013

   http://www.hxa.name/minilight

------------------------------------------------------------------------------*/


#ifndef Primitives_h
#define Primitives_h


//#include <limits.h>
#include <float.h>




namespace hxa7241
{

/// types ----------------------------------------------------------------------

   // for GCC 4.2

   typedef  unsigned int    intu;

//   typedef  signed   char   byte;
   typedef  unsigned char   byteu;
//   typedef  signed   short  short16;
//   typedef  unsigned short  short16u;
   typedef  signed   int    int32;
   typedef  unsigned int    int32u;
//   typedef  signed   long   long64;
//   typedef  unsigned long   long64u;

   typedef  float           real32;
   typedef  double          real64;


/// constants ------------------------------------------------------------------
//   const byte     BYTE_MIN      = SCHAR_MIN;
//   const byte     BYTE_MAX      = SCHAR_MAX;
//   const int      BYTE_BITS     = 8;
//   const byteu    BYTEU_MIN     = 0;
//   const byteu    BYTEU_MAX     = UCHAR_MAX;
//   const int      BYTEU_BITS    = 8;
//
//   const short16  SHORT16_MIN   = SHRT_MIN;
//   const short16  SHORT16_MAX   = SHRT_MAX;
//   const int      SHORT16_BITS  = 16;
//   const short16u SHORT16U_MIN  = 0;
//   const short16u SHORT16U_MAX  = USHRT_MAX;
//   const int      SHORT16U_BITS = 16;
//
//   const int32    INT32_MIN     = INT_MIN;
//   const int32    INT32_MAX     = INT_MAX;
//   const int      INT32_BITS    = 32;
//   const int32u   INT32U_MIN    = 0;
//   const int32u   INT32U_MAX    = UINT_MAX;
//   const int      INT32U_BITS   = 32;
//
//   const long64   LONG64_MIN    = LONG_MIN;
//   const long64   LONG64_MAX    = LONG_MAX;
//   const int      LONG64_BITS   = 64;
//   const long64u  LONG64U_MIN   = 0;
//   const long64u  LONG64U_MAX   = ULONG_MAX;
//   const int      LONG64U_BITS  = 64;


//   const real32   REAL32_MIN_POS    = static_cast<real32>(FLT_MIN);
   const real32   REAL32_MIN_NEG    = static_cast<real32>(-FLT_MAX);
   const real32   REAL32_MAX        = static_cast<real32>(FLT_MAX);
//   const real32   REAL32_EPSILON    = static_cast<real32>(FLT_EPSILON);
//   const real32   REAL32_ALMOST_ONE = static_cast<real32>(1.0f - FLT_EPSILON);
//   const real32   REAL32_SMALL      = static_cast<real32>(1.0e-12f);
//   const real32   REAL32_LARGE      = static_cast<real32>(1.0e+12f);

//   const real64   REAL64_MIN_POS    = static_cast<real64>(DBL_MIN);
   const real64  REAL64_MIN_NEG    = static_cast<real64>(-DBL_MAX);
   const real64  REAL64_MAX        = static_cast<real64>(DBL_MAX);
//   const real64   REAL64_EPSILON    = static_cast<real64>(DBL_EPSILON);
//   const real64   REAL64_ALMOST_ONE = static_cast<real64>(1.0f - DBL_EPSILON);
//   const real64   REAL64_SMALL      = static_cast<real64>(1.0e-12);
//   const real64   REAL64_LARGE      = static_cast<real64>(1.0e+12);

}//namespace




#endif//Primitives_h
