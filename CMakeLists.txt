cmake_minimum_required(VERSION 3.18)
project(CSFMLTest C)

set(CMAKE_C_STANDARD 11)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

add_executable(CSFMLTest main.c)
target_link_libraries(CSFMLTest csfml-system csfml-window csfml-graphics csfml-network csfml-audio)