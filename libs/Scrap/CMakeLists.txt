cmake_minimum_required(VERSION 3.20)
project("Scrap")

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)

option(DYNAMIC_LIB "Compline dll or static lib" ON)
option(TEST_ENABLE "On tests" OFF)
option(USE_RECEIVER "Add receiver libraries" ON)
option(USE_FORMATER "Add formater libraries" ON)
option(USE_EXTRACTOR "Add extractor libraries" ON)
option(USE_CACHER "Add cacher libraries" ON)
option(USE_FILTERER "Add filterer libraries" ON)

find_package(CURL REQUIRED)  
find_package(tinyxml2 REQUIRED) 

if (USE_RECEIVER) 
	list(APPEND EXTRA_INCLUDES 
		"src/htmlreceiver.cpp"
		"src/receiver.cpp")
endif ()
if (USE_FORMATER) 
	list(APPEND EXTRA_INCLUDES 
		"src/htmlformater.cpp"
		"src/formater.cpp")
endif ()
if (USE_EXTRACTOR) 
	list(APPEND EXTRA_INCLUDES 
		"src/htmlextractor.cpp"
		"src/extractor.cpp")
endif ()
if (USE_CACHER) 
	list(APPEND EXTRA_INCLUDES 
		"src/xmlcacher.cpp"  
		"src/cacher.cpp")
endif ()
if (USE_FILTERER) 
	list(APPEND EXTRA_INCLUDES 
		"src/vectorfilterer.cpp"
		"src/xmlfilterer.cpp"
		"src/filterer.cpp")
endif ()

if (DYNAMIC_LIB)
	add_library(${PROJECT_NAME} SHARED 
		"src/scrapexception.cpp"
		${EXTRA_INCLUDES})
else ()
	add_library(${PROJECT_NAME} STATIC 
		"src/scrapexception.cpp"
		${EXTRA_INCLUDES})
endif ()

target_include_directories(${PROJECT_NAME} PUBLIC
	"include"
	${CURL_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC
	${CURL_LIBRARIES}
	tinyxml2::tinyxml2)

set_target_properties(Scrap PROPERTIES
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

# Testing
if (TEST_ENABLE) 
	add_subdirectory("test")
endif()