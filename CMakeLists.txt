cmake_minimum_required(VERSION 3.10)
project(ComplexMultiLanguageIDE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(Threads REQUIRED)

# Define source files
set(SOURCES
    src/main.cpp
    src/editor.cpp
    src/language_support.cpp
    src/ui_components.cpp
)

# Define header files
set(HEADERS
    include/ide.h
)

# Create executable
add_executable(ide_app ${SOURCES} ${HEADERS})

# Set include directories
target_include_directories(ide_app PRIVATE include)

# Link libraries
target_link_libraries(ide_app ${CMAKE_THREAD_LIBS_INIT})

# Set output directory
set_target_properties(ide_app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Install target
install(TARGETS ide_app DESTINATION bin)