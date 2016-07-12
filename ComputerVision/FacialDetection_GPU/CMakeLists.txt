cmake_minimum_required(VERSION 2.8)
project( Haar_GPU )
find_package( OpenCV REQUIRED )
add_executable( Haar_GPU Haar_GPU.cpp )
target_link_libraries( Haar_GPU ${OpenCV_LIBS} )

