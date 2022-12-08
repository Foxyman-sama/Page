cmake_minimum_required (VERSION 3.8)

project ("PageScraper")

find_package(CURL REQUIRED)

include_directories("include")

set(PROJECT_INCLUDE
	"include/test.hpp"
	"include/connector.hpp"
	"include/parser.hpp"
	"include/parsedresult.hpp"
	"include/formater.hpp"
	"include/downloader.hpp"
	"include/saver.hpp"
	"include/output.hpp"
	"include/checker.hpp"
	"include/indexer.hpp"
	"include/cacher.hpp"
	"include/userfunctions.hpp"
	"include/stringmanipulator.hpp"
)
set(PROJECT_SOURCE
	"src/test.cpp" 
	"src/connector.cpp"
	"src/parser.cpp"
	"src/parsedresult.cpp"
	"src/formater.cpp"
	"src/downloader.cpp"
	"src/saver.cpp"
	"src/output.cpp"
	"src/checker.cpp"
	"src/indexer.cpp"
	"src/cacher.cpp"
	"src/userfunctions.cpp"
	"src/stringmanipulator.cpp"
)

add_executable(PageScraper  
	src/main.cpp
	${PROJECT_INCLUDE}
	${PROJECT_SOURCE}
)

target_link_libraries(PageScraper PRIVATE
	${CURL_LIBRARIES}
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET PageScraper PROPERTY CXX_STANDARD 23)
endif()