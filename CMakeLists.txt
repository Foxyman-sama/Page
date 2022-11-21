# CMakeList.txt: проект CMake для PageScraper; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("PageScraper")

include_directories(
	"include"
)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (PageScraper "PageScraper.cpp" "PageScraper.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET PageScraper PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
