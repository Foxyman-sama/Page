cmake_minimum_required(VERSION 3.20)
project(PageScraper)

if (${CMAKE_SIZEOF_VOID_P} EQUAL 8) 
	list(APPEND EXTRAS_LIBRARY 
		"E:/Projects/Visual Studio/PageScraper/lib/Scrap/build/x64")
else ()
	list(APPEND EXTRAS_LIBRARY 
		"E:/Projects/Visual Studio/PageScraper/lib/Scrap/build/x32")
endif ()

target_link_directories(${PROJECT_NAME} PRIVATE
	EXTRAS_LIBRARY)
