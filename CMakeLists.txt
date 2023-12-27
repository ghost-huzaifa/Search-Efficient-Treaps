cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
project(AVLProject)

# Set the compilers to Clang
#set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
#set(CMAKE_C_COMPILER "/usr/bin/clang")

# Add include directories
include_directories(include)

# Globbing source files
file(GLOB SOURCES "src/*.cpp")

# Add executable and link libraries
add_executable(output main.cpp ${SOURCES})
#add_executable(AVL main.cpp AVL.cpp BST.cpp BInaryTree.cpp)
# Set compiler flags (adjust as needed)
#target_compile_options(AVL PRIVATE -Wall -Wextra -Werror)

# Specify additional dependencies if needed
# target_link_libraries(AVL PRIVATE YourLibraries)
