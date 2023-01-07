cmake_minimum_required(VERSION 3.20)
project(Page)

add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC
	"${PROJECT_SOURCE_DIR}/libs/Scrap/include")
target_link_libraries(${PROJECT_NAME} PUBLIC
	Scrap)

add_subdirectory(libs/Scrap)