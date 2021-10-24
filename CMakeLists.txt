project(LogManager)

cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost 1.56 COMPONENTS date_time filesystem REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(Catch2 CONFIG REQUIRED)


include(CTest)
include_directories(src/include inih/cpp)
add_subdirectory(src)
add_subdirectory(test)
