cmake_minimum_required(VERSION 3.1)
project(test VERSION 0.1.0)

# set(CMAKE_CXX_FLAGS "-O0 -std=c++14 -Wall")
set(CMAKE_CXX_FLAGS "-O0 -std=c++17")

include_directories(/usr/local/include) # vulkan
include_directories(/opt/homebrew/Cellar/glfw/3.3.4/include)
include_directories(external/glm)

link_directories(/usr/local/lib) # vulkan
link_directories(/opt/homebrew/Cellar/glfw/3.3.4/lib)

add_executable(app
    main.cpp
    MainInternal.cpp
    XXFramework.cpp
    external/imgui/imgui.cpp
    external/imgui/imgui_draw.cpp
    external/imgui/imgui_tables.cpp
    external/imgui/imgui_widgets.cpp
    external/imgui/imgui_impl_glfw.cpp
    external/imgui/imgui_impl_vulkan.cpp
    external/imgui/imgui_demo.cpp
)
# add_subdirectory(imgui)

target_link_libraries(app libvulkan.1.2.189.dylib libvulkan.1.dylib libglfw.3.dylib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

