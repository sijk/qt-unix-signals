CMAKE_MINIMUM_REQUIRED(VERSION 2.8.3)

project(QTSignals)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

SET(QTSignal_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR} CACHE INTERNAL "QTSignal Include Dir")

find_package(Qt5Widgets)
find_package(Qt5Core)
SET(GCC_COMPILE_FLAGS "-fPIC -std=c++11 -pg")

option(CMAKE_ENABLE "Enable automatic path configuration" ON)


# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)


include_directories(
	${Qt5Widgets_INCLUDE_DIRS})
add_library(QTSignal SHARED
		sigwatch.cpp
		)
target_link_libraries (QTSignal
		${Qt5Widgets_LIBRARIES}
)
