cmake_minimum_required(VERSION 3.22)

# Enable the export of the compile_commands.json file for YCM support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add the include and src subdirectories
file(GLOB avrlibextra_src "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc")
file(GLOB avrlibextra_hh  "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hh")
add_library(AVRLibExtra "" )

target_sources(AVRLibExtra
    PRIVATE
    "${avrlibextra_src}"

    PUBLIC
    "${avrlibextra_hh}"
    )

target_include_directories(AVRLibExtra
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    )

add_avr_library(AVRLibExtra 
                "${avrlibextra_src}" 
                )
message(STATUS "Library AVRLibExtra added ${avrlibextra_src}")
