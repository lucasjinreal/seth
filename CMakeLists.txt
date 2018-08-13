cmake_minimum_required(VERSION 3.8)
project(seth_main)
set(CMAKE_CXX_STANDARD 11)


file(GLOB_RECURSE SOURCES
        src/*.cpp
        src/*.h
        lib/*.cpp)

find_package(OpenCV 3.0)
if (NOT OpenCV_FOUND)
    message(FATAL_ERROR "OpenCV > 3.0 not found.")
else()
    message(STATUS "Find OpenCV.")
    INCLUDE_DIRECTORIES(  ${OpenCV_INCLUDE_DIRS}  )
endif ()


set(BUILD_SHARED_LIBS OFF)

add_executable(seth_main main.cpp ${SOURCES})
target_link_libraries(seth_main ${OpenCV_LIBS})