cmake_minimum_required (VERSION 3.8)

project ("PageScraper")

find_package(CURL REQUIRED)

include_directories("include")

set(PROJECT_INCLUDE
	"include/pagescraper.hpp"
)
set(PROJECT_SOURCE
	"src/pagescraper.cpp"
)

add_executable (PageScraper  
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