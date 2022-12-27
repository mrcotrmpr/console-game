cmake_minimum_required(VERSION 3.23)
project(cplus)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_PREFIX_PATH C:/cmake_prefix_path/sqlite3)
find_package(SQLite3 REQUIRED)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS ./src/*.cpp)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS ./include/*.hpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(cplus sqlite3)

target_include_directories(cplus PUBLIC include)
target_include_directories(cplus PRIVATE ${SQLite3_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD_REQUIRED ON)