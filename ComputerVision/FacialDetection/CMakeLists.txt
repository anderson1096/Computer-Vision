cmake_minimum_required(VERSION 2.8)
project( Haar )
find_package( OpenCV REQUIRED )
add_executable( Haar Haar.cpp )
target_link_libraries( Haar ${OpenCV_LIBS} )

