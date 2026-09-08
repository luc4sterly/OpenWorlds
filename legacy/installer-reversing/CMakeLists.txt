cmake_minimum_required(VERSION 3.15)
project(WorldsChat LANGUAGES C)

# Set C standard (the original code relies on MSVC extensions, but C99 works for most parts)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Source files
set(SRC_ROOT "${CMAKE_CURRENT_SOURCE_DIR}")

# Create source directory structure
file(MAKE_DIRECTORY ${SRC_ROOT}/src)
file(MAKE_DIRECTORY ${SRC_ROOT}/include)

# Copy the original decompiled file into src/ (preserve original name)
configure_file(${SRC_ROOT}/Worlds1900.exe.c ${SRC_ROOT}/src/worlds_original.c COPYONLY)

# Add platform‑specific source files (will be created later if missing)
set(PLATFORM_SRC "${SRC_ROOT}/src/platform_win32.c" "${SRC_ROOT}/src/platform_stub.c")

add_executable(WorldsChat
    src/main.c
    src/worlds_original.c
    ${PLATFORM_SRC}
)

# Include directory for public headers (to be added later)
target_include_directories(WorldsChat PRIVATE ${SRC_ROOT}/include)

# Link against Win32 libraries on Windows
if (WIN32)
    target_link_libraries(WorldsChat PRIVATE user32 gdi32 winmm)
endif()

# Enable warnings
if (MSVC)
    target_compile_options(WorldsChat PRIVATE /W4)
else()
    target_compile_options(WorldsChat PRIVATE -Wall -Wextra -Werror)
endif()
