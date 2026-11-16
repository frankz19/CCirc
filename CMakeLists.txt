cmake_minimum_required(VERSION 3.20)
project(CCircCompiler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Designar QUIET)

add_executable(ccirc
    src/main.cpp
    src/ccirc_lexer.cpp
    src/ccirc_parser.cpp
    src/tree_printer.cpp
)

target_include_directories(ccirc PRIVATE include)

if(Designar_FOUND)
    target_link_libraries(ccirc PRIVATE Designar::Designar)
elseif(DEFINED DESIGNAR_INCLUDE_DIR)
    target_include_directories(ccirc PRIVATE ${DESIGNAR_INCLUDE_DIR})
endif()