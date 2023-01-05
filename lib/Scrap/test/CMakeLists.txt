cmake_minimum_required(VERSION 3.20)

option(RECEIVE_TEST   "ENABLE RECEIVE`S TEST" ON)
option(FORMATER_TEST  "ENABLE FORMATER`S TEST" ON)
option(EXTRACTOR_TEST "ENABLE EXTRACTOR`S TEST" ON)
option(CACHER_TEST    "ENABLE CACHER`S TEST" ON)
option(FILTERER_TEST  "ENABLE FILTERER`S TEST" ON)

add_executable(ScrapTest main.cpp) 
configure_file(Test.h.in Test.h)

target_include_directories(ScrapTest PRIVATE 
    "${PROJECT_BINARY_DIR}")
target_link_libraries(ScrapTest PRIVATE Scrap)

add_custom_command(TARGET ScrapTest POST_BUILD       
    COMMAND ${CMAKE_COMMAND} -E copy_if_different 
    "${PROJECT_BINARY_DIR}/Scrap.dll"     
    $<TARGET_FILE_DIR:ScrapTest>)   
add_custom_command(TARGET ScrapTest POST_BUILD       
    COMMAND ${CMAKE_COMMAND} -E copy_if_different 
    "${PROJECT_BINARY_DIR}/libcurl-d.dll"     
    $<TARGET_FILE_DIR:ScrapTest>)    
