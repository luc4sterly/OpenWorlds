# The transpiled program's project (vita/tools/transpile.sh puts it in
# place of Clearwing's own): Clearwing's runtime libraries plus SDL2, which
# our platform natives (clearwing/src/openworlds) use for the screen, input
# and sound, on Linux and on the PSVita.
cmake_minimum_required(VERSION 3.22)
project(dist)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-volatile -fwrapv")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
find_package(ZLIB REQUIRED)
find_package(ZZip REQUIRED)
find_package(FFI REQUIRED)
find_package(SDL2 REQUIRED)

file(GLOB_RECURSE SRCS src/*.cpp)
include_directories(src)
add_executable(dist ${SRCS})

target_compile_options(dist PRIVATE -Wno-return-type)

target_include_directories(dist PUBLIC ${ZLIB_INCLUDE_DIRS} ${ZZip_INCLUDE_DIRS} ${FFI_INCLUDE_DIRS})
target_link_libraries(dist stdc++fs ${ZLIB_LIBRARIES} ${ZZip_LIBRARIES} ${FFI_LIBRARIES} SDL2::SDL2)
