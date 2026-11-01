cmake_minimum_required(VERSION 3.10...4.0.0)

project(RT_Weekend LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCE_ONE_WEEKEND
    src/InOneWeekend/main.cc
    # src/InOneWeekend
)

include_directories(src)

message(STATUS "Compiler ID: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Release flags: ${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS "Debug flags: ${CMAKE_CXX_FLAGS_DEBUG}")

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options("/W4")
    add_compile_options("/we 4265")
    add_compile_options("/we 5204")
    add_compile_options("/wd 4100")

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-Wnon-virtual-dtor)
    add_compile_options(-Wreorder)
    add_compile_options(-Wmaybe-uninitialized)
    add_compile_options(-Wunused-variable)

elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wnon-virtual-dtor)
    add_compile_options(-Wreorder)
    add_compile_options(-Wsometimes-uninitialized)
    add_compile_options(-Wunused-variable)
endif()

add_executable(inOneWeekend ${SOURCE_ONE_WEEKEND})