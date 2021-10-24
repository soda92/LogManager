
add_executable(test_directories.out test_directories.cpp)
target_link_libraries(test_directories.out Boost::date_time 
Boost::filesystem fmt::fmt)

add_executable(test.out test.cc)
target_link_libraries(test.out Boost::date_time 
Boost::filesystem fmt::fmt)

add_executable(Test2.out Test.cpp)
target_link_libraries(Test2.out Boost::date_time 
Boost::filesystem fmt::fmt)

add_executable(CreateFoldersAndFiles.out CreateFoldersAndFiles.cpp)
target_link_libraries(CreateFoldersAndFiles.out Boost::date_time 
Boost::filesystem fmt::fmt)

add_executable(Clean.out Clean.cpp)
target_link_libraries(Clean.out Boost::date_time 
Boost::filesystem fmt::fmt)
