cmake_minimum_required(VERSION 3.10)

project(xwork)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Dependencies
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

# Includes
include_directories(inc)

# Source
file(GLOB SOURCES "src/*.cpp")
add_library(xwork STATIC ${SOURCES})

# Link
target_link_libraries(xwork 
    ${SDL2_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
    ${SDL2_MIXER_LIBRARIES}
    stdc++
    m
)