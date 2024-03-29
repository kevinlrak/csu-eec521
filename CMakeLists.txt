# File:        DRESS/CMakeLists.txt
# Authors:     Kevin Rak
#              Eric Eilberg
# Description: This is the main project file. It defines all of the important project files and targets.

cmake_minimum_required(VERSION 3.5)
project(DRESS)

# Simplify target creation
include(${CMAKE_SOURCE_DIR}/cmake/make_target.cmake)

# Subdirectory containing utility classes for database, webserver, messaging, etc.
# NOTE: any external dependencies should be fully encapsulated in targets within the utilities directory
add_subdirectory(${CMAKE_SOURCE_DIR}/utilities)

# If we do not have the WebServer or Database utility libraries, then we cannot build the GUI
if(TARGET WebServer AND TARGET Database)
	make_target(EXECUTABLE GUI)
	target_compile_definitions(GUI PRIVATE DRESS_WWW_DIR="${CMAKE_CURRENT_SOURCE_DIR}/GUI/www")
	target_link_libraries(GUI PRIVATE WebServer)
	target_link_libraries(GUI PRIVATE Database)
endif()

add_custom_target(RSM SOURCES RSM/RSM.py)

project(DRESS) # Just to restore the top-level project name.

# Non-Building target which contains other types of project files
add_custom_target(_files SOURCES
	.travis.yml
	.gitignore
	Doxyfile
	cmake/Toolchain-RaspberryPi.cmake
	cmake/get_dependency.cmake
)
