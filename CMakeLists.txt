cmake_minimum_required(VERSION 3.24)

project(cppproject)
add_executable(cppproject ./main.cpp audio.h shapes.h)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

file(GLOB SOURCES
        *.h
        *.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} ${GTKMM_LIBRARIES})