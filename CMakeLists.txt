cmake_minimum_required(VERSION 3.22)

# Enable the export of the compile_commands.json file for YCM support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add the include and src subdirectories
file(GLOB avrlibextra_src "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc")
add_library(AVRLibExtra PUBLIC "${avrlibextra_src}")

# Add the inlcude directory
target_include_directories(AVRLibExtra PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
