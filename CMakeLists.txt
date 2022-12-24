cmake_minimum_required(VERSION 3.23)
project(cplus)

set(CMAKE_CXX_STANDARD 17)

find_package(SQLite3 REQUIRED)
include_directories(${SQLITE3_INCLUDE_DIR})

target_include_directories(PRIVATE ${SQLite3_INCLUDE_DIR})
target_link_libraries(${SQLite3_LIBRARY})

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS ./src/*.cpp)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS ./include/*.hpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(cplus PUBLIC include)

target_link_libraries(cplus sqlite3)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
