# Specifies minimum version
cmake_minimum_required(VERSION 3.10)

# Project Name
project(VMTranslator)

# Exports compile commands so project libraries can be seen as global
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Sets build type
set(CMAKE_BUILD_TYPE Debug)

# Creates the executable
add_executable(VMTranslator main.c)

# Adds library directories
add_subdirectory(Parser)
add_subdirectory(CodeWriter)

# Links external libraries to the project
target_link_libraries(VMTranslator Parser CodeWriter)
