cmake_minimum_required(VERSION 3.28)


# ------------------- imgui -------------------

set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/imgui-docking)
add_library(IMGUI STATIC)
target_sources(IMGUI 
    PRIVATE
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/imgui_tables.cpp

    PRIVATE
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
    ${IMGUI_DIR}/misc/cpp/imgui_stdlib.cpp
)

target_include_directories(IMGUI
    PUBLIC
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
    ${IMGUI_DIR}/misc/cpp
)

find_package(OpenGL REQUIRED)
target_link_libraries(IMGUI PUBLIC ${OPENGL_LIBRARIES})

# ------------------- glfw -------------------
add_subdirectory(GLFW)
target_include_directories(IMGUI PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/GLFW/include)

# ------------------- rtmidi -------------------

add_subdirectory(rtmidi-master)
