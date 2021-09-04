cmake_minimum_required(VERSION 3.1)
project(test VERSION 0.1.0)

# set(CMAKE_CXX_FLAGS "-O0 -std=c++14 -Wall")
set(CMAKE_CXX_FLAGS "-O0 -std=c++17")

include_directories(/usr/local/include) # vulkan
include_directories(/opt/homebrew/Cellar/glfw/3.3.4/include)
include_directories(glm)

link_directories(/usr/local/lib) # vulkan
link_directories(/opt/homebrew/Cellar/glfw/3.3.4/lib)

add_executable(app
    main.cpp
    XXFramework.cpp
    imgui.cpp
    imgui_draw.cpp
    imgui_tables.cpp
    imgui_widgets.cpp
    imgui_impl_glfw.cpp
    imgui_impl_vulkan.cpp
    imgui_demo.cpp
)
# add_subdirectory(imgui)

target_link_libraries(app libvulkan.1.2.189.dylib libvulkan.1.dylib libglfw.3.dylib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

