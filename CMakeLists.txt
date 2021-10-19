cmake_minimum_required(VERSION 3.21)

find_package(Boost 1.56 REQUIRED COMPONENTS
date_time filesystem iostreams)

add_executable(test_directories.out test_directories.cpp)
target_link_libraries(test_directories.out Boost::date_time 
Boost::filesystem Boost::iostreams)

add_executable(test.out test.cc)
target_link_libraries(test.out Boost::date_time 
Boost::filesystem Boost::iostreams)

add_executable(Test.out Test.cpp)
target_link_libraries(Test.out Boost::date_time 
Boost::filesystem Boost::iostreams)

add_executable(CreateFoldersAndFiles.out CreateFoldersAndFiles.cpp)
target_link_libraries(CreateFoldersAndFiles.out Boost::date_time 
Boost::filesystem Boost::iostreams)

add_executable(DeleteOldFolder.out DeleteOldFolder.cpp)
target_link_libraries(DeleteOldFolder.out Boost::date_time 
Boost::filesystem Boost::iostreams)

add_executable(Clean.out Clean.cpp)
target_link_libraries(Clean.out Boost::date_time 
Boost::filesystem Boost::iostreams)
