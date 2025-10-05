cmake_minimum_required(VERSION 3.10)
project(
  DSA_CODE
  VERSION 1.0
  LANGUAGES CXX)

# Set C++17 as standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Options
option(BUILD_TESTS "Build tests" OFF)
option(ENABLE_WARNINGS "Enable compiler warnings" OFF)

# Compiler warnings
if(ENABLE_WARNINGS)
  if(MSVC)
    add_compile_options(/W4 /WX)
  else()
    add_compile_options(-Wall -Wextra -Wpedantic)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
      add_compile_options(-Werror)
    endif()
  endif()
endif()

# --- Dependencies ---
find_package(fmt REQUIRED)

# Add shared library
add_subdirectory(lib)

# --- Build each module file as its own executable ---
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/modules/*.cpp)

foreach(source ${SOURCES})
  get_filename_component(EXECUTABLE ${source} NAME_WE)
  add_executable(${EXECUTABLE} ${source})
  target_link_libraries(${EXECUTABLE} PRIVATE utils)
endforeach()

# Tests
if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
