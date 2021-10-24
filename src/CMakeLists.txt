add_executable(DeleteOldFolder.out DeleteOldFolder.cpp)
target_link_libraries(DeleteOldFolder.out Boost::date_time 
Boost::filesystem fmt::fmt)
