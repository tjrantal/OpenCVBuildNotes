Notes for building, and testing openCV with MSYS and MinGW in Win7

BUILD IN MINGW-WINDOWS
The build requires runtmchk.lib. That was found from c:\Program files (x86)\visualstudio\amd64, so copied that to mingw/lib
IIP needed to be disabled (otherwise the build failed)
Disabled shared libraries as well (shared may have worked, but I plan to use the exe on another PC, so reckoned a static build is easier to transfer).

cmake -G MSYS Makefiles -D BUILD_SHARED_LIBS=OFF -D WITH_IPP=OFF -D CMAKE_BUILD_TYPE=RELEASE -DCMAKE_INSTALL_PREFIX=/opencv ../ocvGIT/opencv

INSTALL:

pkg-config file opencv.pc needs to be manually copied from buildFolder/unix-install

The install prefix needs to be pointed to the correct place (if not correct..)

The following additional libraries need to be linked in windows:
${exec_prefix}/lib/libIlmImf.a ${exec_prefix}/lib/libzlib.a ${exec_prefix}/lib/liblibjasper.a ${exec_prefix}/lib/liblibjpeg.a ${exec_prefix}/lib/liblibpng.a ${exec_prefix}/lib/liblibtiff.a ${exec_prefix}/lib/liblibwebp.a  -lpthread -lcomctl32 -lgdi32 -lvfw32 -lole32 -loleaut32 -luuid

The order of opencv libraries needs to be modified as well (for some reason the order matters)
Libs: ${exec_prefix}/lib/libopencv_highgui300.a ${exec_prefix}/lib/libopencv_features2d300.a ${exec_prefix}/lib/libopencv_calib3d300.a ${exec_prefix}/lib/libopencv_imgproc300.a ${exec_prefix}/lib/libopencv_videostab300.a ${exec_prefix}/lib/libopencv_video300.a ${exec_prefix}/lib/libopencv_videoio300.a  ${exec_prefix}/lib/libopencv_core300.a    ${exec_prefix}/lib/libopencv_imgcodecs300.a ${exec_prefix}/lib/libopencv_ml300.a    ${exec_prefix}/lib/libopencv_objdetect300.a ${exec_prefix}/lib/libopencv_ts300.a ${exec_prefix}/lib/libopencv_flann300.a  ${exec_prefix}/lib/libopencv_photo300.a ${exec_prefix}/lib/libopencv_shape300.a ${exec_prefix}/lib/libopencv_stitching300.a ${exec_prefix}/lib/libopencv_superres300.a

The full file:
# Package Information for pkg-config

prefix=D:/timo/compiler/mingw64
exec_prefix=${prefix}
libdir=
includedir_old=${prefix}/include/opencv
includedir_new=${prefix}/include

Name: OpenCV
Description: Open Source Computer Vision Library
Version: 3.0.0
Libs: ${exec_prefix}/lib/libopencv_highgui300.a ${exec_prefix}/lib/libopencv_features2d300.a ${exec_prefix}/lib/libopencv_calib3d300.a ${exec_prefix}/lib/libopencv_imgproc300.a ${exec_prefix}/lib/libopencv_videostab300.a ${exec_prefix}/lib/libopencv_video300.a ${exec_prefix}/lib/libopencv_videoio300.a  ${exec_prefix}/lib/libopencv_core300.a    ${exec_prefix}/lib/libopencv_imgcodecs300.a ${exec_prefix}/lib/libopencv_ml300.a    ${exec_prefix}/lib/libopencv_objdetect300.a ${exec_prefix}/lib/libopencv_ts300.a ${exec_prefix}/lib/libopencv_flann300.a  ${exec_prefix}/lib/libopencv_photo300.a ${exec_prefix}/lib/libopencv_shape300.a ${exec_prefix}/lib/libopencv_stitching300.a ${exec_prefix}/lib/libopencv_superres300.a ${exec_prefix}/lib/libIlmImf.a ${exec_prefix}/lib/libzlib.a ${exec_prefix}/lib/liblibjasper.a ${exec_prefix}/lib/liblibjpeg.a ${exec_prefix}/lib/liblibpng.a ${exec_prefix}/lib/liblibtiff.a ${exec_prefix}/lib/liblibwebp.a  -lpthread -lcomctl32 -lgdi32 -lvfw32 -lole32 -loleaut32 -luuid
Cflags: -I${includedir_old} -I${includedir_new}

