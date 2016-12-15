cmake_minimum_required(VERSION 3.5)
project(Prism)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)

set(CMAKE_PREFIX_PATH "/Users/deranen/Programming/Qt/5.7/clang_64/")
find_package(Qt5Widgets REQUIRED)
find_package(OpenGL)

FIND_LIBRARY(OpenGL_LIBRARY OpenGL)

set(SOURCE_FILES main.cpp OpenGLWindow.cpp OpenGLWindow.h gl/ErrorHandling.h gl/ErrorHandling.cpp PrismApp.cpp PrismApp.h Document.cpp Document.h DocumentSettings.cpp DocumentSettings.h GridSettings.cpp GridSettings.h TriangleWidget.cpp TriangleWidget.h ViewWidget.cpp ViewWidget.h DisplayPipeline.cpp DisplayPipeline.h)
add_executable(Prism ${SOURCE_FILES})

target_link_libraries(Prism Qt5::Widgets ${OpenGL_LIBRARY})