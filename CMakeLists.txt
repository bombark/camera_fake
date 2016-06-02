cmake_minimum_required (VERSION 2.6)
project (camera_fake)

find_package( OpenCV REQUIRED )

add_executable (camera_fake src/main.cpp)
target_link_libraries (camera_fake tiobj ${OpenCV_LIBS})

install(TARGETS camera_fake DESTINATION bin)
