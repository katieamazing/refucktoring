/*------------------------------------------------------------------------------

   MiniLight C++ : minimal global illumination renderer
   Harrison Ainsworth / HXA7241 : 2006-2011, 2013

   http://www.hxa.name/minilight

------------------------------------------------------------------------------*/


#include <signal.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cstdlib>

#include "primitives.h"

#include "random.h"
#include "image.h"
#include "scene.h"
#include "camera.h"




namespace
{

   using namespace hxa7241;


/// user messages --------------------------------------------------------------

const char BANNER_MESSAGE[] =
"\n  MiniLight 1.6 C++ - http://www.hxa.name/minilight\n"
//"\n  MiniLight 1.6 C++ HDRI - http://www.hxa.name/minilight\n"   // HDRI
"\n";

const char HELP_MESSAGE[] =
"\n"
"----------------------------------------------------------------------\n"
"  MiniLight 1.6 C++\n"
//"  MiniLight 1.6 C++ HDRI\n"   // HDRI
"\n"
"  Harrison Ainsworth / HXA7241 : 2006-2011, 2013\n"
"  http://www.hxa.name/minilight\n"
"\n"
"  2013-05-04\n"
"----------------------------------------------------------------------\n"
"\n"
"MiniLight is a minimal global illumination renderer.\n"
"\n"
"usage:\n"
"  minilight modelFilePathName\n"
"\n"
"The model text file format is:\n"
"  #MiniLight\n"
"\n"
"  iterations\n"
"\n"
"  imagewidth imageheight\n"
"  viewposition viewdirection viewangle\n"
"\n"
"  skyemission groundreflection\n"
"\n"
"  vertex0 vertex1 vertex2 reflectivity emitivity\n"
"  vertex0 vertex1 vertex2 reflectivity emitivity\n"
"  ...\n"
"\n"
"- where iterations and image values are integers, viewangle is a real,\n"
"and all other values are three parenthised reals. The file must end\n"
"with a newline. E.g.:\n"
"  #MiniLight\n"
"\n"
"  100\n"
"\n"
"  200 150\n"
"  (0 0.75 -2) (0 0 1) 45\n"
"\n"
"  (3626 5572 5802) (0.1 0.09 0.07)\n"
"\n"
"  (0 0 0) (0 1 0) (1 1 0)  (0.7 0.7 0.7) (0 0 0)\n"
"\n";




/// constants ------------------------------------------------------------------

const char MODEL_FORMAT_ID[] = "#MiniLight";




/// ctrl-c handling ------------------------------------------------------------

void sigintHandler
(
   int arg
)
{
   if( SIGINT == arg )
   {
      std::cout << "\ninterrupted\n";
      ::exit( EXIT_SUCCESS );
   }
}

}




/// entry point ////////////////////////////////////////////////////////////////

int main
(
   int   argc,
   char* argv[]
)
{
   int returnValue = EXIT_FAILURE;

   // catch everything
   try
   {
      // check for help request
      if( (argc <= 1) || (std::string(argv[1]) == "-?") ||
         (std::string(argv[1]) == "--help") )
      {
         std::cout << HELP_MESSAGE;
      }
      // execute
      else
      {
         std::cout << BANNER_MESSAGE;

         // make random generator
         hxa7241_general::Random random;

         // get file names
         const std::string modelFilePathname( argv[1] );
         const std::string imageFilePathname( modelFilePathname + ".ppm" );
         // HDRI
         //const std::string imageFilePathname( modelFilePathname + ".rgbe" );

         // open model file
         std::ifstream modelFile( modelFilePathname.c_str() );
         modelFile.exceptions( std::ios::badbit | std::ios::eofbit );

         // check model file format identifier at start of first line
         {
            std::string formatId;
            modelFile >> formatId;
            if( std::string(MODEL_FORMAT_ID) != formatId )
            {
               throw std::runtime_error( "unrecognised model format" );
            }
         }

         // read frame iterations
         int32 iterations = 0;
         modelFile >> iterations;

         // create top-level rendering objects with model file
               hxa7241_minilight::Image  image ( modelFile );
         const hxa7241_minilight::Camera camera( modelFile );
         const hxa7241_minilight::Scene scene( modelFile, camera.getEyePoint());

         modelFile.close();

         // setup ctrl-c/interruption/sigint handler
         ::signal( SIGINT, sigintHandler );

         // do progressive refinement render loop
         for( int32 frameNo = 1;  frameNo <= iterations;  ++frameNo )
         {
            // display current frame number
            (std::cout << "\riteration: " << frameNo).flush();

            // render a frame
            camera.getFrame( scene, random, image );

            // save image at twice error-halving rate, and at start and end
            if( ((frameNo & (frameNo - 1)) == 0) | (iterations == frameNo) )
            {
               // open image file
               std::ofstream imageFile( imageFilePathname.c_str(),
                  std::ios::binary );
               imageFile.exceptions( std::ios::badbit | std::ios::failbit |
                  std::ios::eofbit );

               // write image frame to file
               image.getFormatted( imageFile, frameNo );

               imageFile.close();
            }
         }

         std::cout << "\nfinished\n";
      }

      returnValue = EXIT_SUCCESS;
   }
   // print exception message
   catch( const std::exception& e )
   {
      std::cout << '\n' << "*** execution failed:  " << e.what() << '\n';
   }
   catch( ... )
   {
      std::cout << '\n' << "*** execution failed" << '\n';
   }

   return returnValue;
}
