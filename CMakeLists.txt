cmake_minimum_required (VERSION 3.8)

project ("PageScraper")

find_package(CURL REQUIRED)

include_directories(
	"include"
	"include/cache"
	"include/checker"
	"include/connector"
	"include/downloader"
	"include/format"
	"include/helpfunctions"
	"include/indexer"
	"include/io"
	"include/parser"
	"include/prep"
	"include/print"
	"include/saver"
	"include/test"
)

set(PROJECT_INCLUDE
	"include/headers.hpp"
	"include/test/test.hpp"
	"include/connector/connector.hpp"
	"include/parser/parser.hpp"
	"include/parser/parsedresult.hpp"
	"include/format/formater.hpp"
	"include/downloader/downloader.hpp"
	"include/saver/saver.hpp"
	"include/print/print.hpp"
	"include/checker/checker.hpp"
	"include/indexer/indexer.hpp"
	"include/cache/cacher.hpp"
	"include/helpfunctions/userfunctions.hpp"
	"include/helpfunctions/stringmanipulator.hpp"
	"include/helpfunctions/vectormanipulator.hpp"
	"include/prep/prep.hpp"
	"include/io/ioutput.hpp"
	"include/io/iinput.hpp"
	"include/cache/cachereader.hpp"
	"include/cache/cachewriter.hpp"
)
set(PROJECT_SOURCE
	"src/test/test.cpp" 
	"src/connector/connector.cpp"
	"src/parser/parser.cpp"
	"src/parser/parsedresult.cpp"
	"src/format/formater.cpp"
	"src/downloader/downloader.cpp"
	"src/saver/saver.cpp"
	"src/print/print.cpp"
	"src/checker/checker.cpp"
	"src/indexer/indexer.cpp"
	"src/cache/cacher.cpp"
	"src/helpfunctions/userfunctions.cpp"
	"src/helpfunctions/stringmanipulator.cpp"
	"src/helpfunctions/vectormanipulator.cpp"
	"src/prep/prep.cpp"
	"src/io/ioutput.cpp"
	"src/io/iinput.cpp"
	"src/cache/cachereader.cpp"
	"src/cache/cachewriter.cpp"
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