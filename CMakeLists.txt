cmake_minimum_required(VERSION 3.16)
project(PointersAndThings)

set(CMAKE_CXX_STANDARD 20)

add_executable(PointersAndThings main_pointers.cpp)
add_executable(Const main_const.cpp)
add_executable(Multithread main_multithread.cpp)

if (CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    option(ENABLE_SANITISER "Enable sanitiser" TRUE)
    if (ENABLE_SANITISER)
        message("Memory sanitizer on...")
        target_compile_options(PointersAndThings PRIVATE -fsanitize=leak -O1 -g -fno-omit-frame-pointer -fno-optimize-sibling-calls)
        target_link_libraries(PointersAndThings PRIVATE -fsanitize=leak)
    endif ()
endif ()



