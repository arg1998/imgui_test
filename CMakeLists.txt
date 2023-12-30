cmake_minimum_required(VERSION 3.28)

# set(CMAKE_C_COMPILER clang)
# set(CMAKE_CXX_COMPILER clang++)

project(eZe1 VERSION 1.0.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)

set(EZE1_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/)

add_executable(eZe1 ${EZE1_DIR}/entry.cpp)

target_include_directories(eZe1 PRIVATE ${EZE1_DIR})




# ------------------- Linking Libs ------------------- #
add_subdirectory(external)

# Link the IMGUI library
target_link_libraries(eZe1 PRIVATE IMGUI)

# Link GLFW library
target_link_libraries(eZe1 PRIVATE glfw)

