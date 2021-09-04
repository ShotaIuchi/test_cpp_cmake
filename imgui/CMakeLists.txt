cmake_minimum_required(VERSION 3.1)
project(imgui VERSION 0.1.0)

add_library(imgui STATIC
  imgui.cpp
  imgui_draw.cpp
  imgui_tables.cpp
  imgui_widgets.cpp
  imgui_demo.cpp
)