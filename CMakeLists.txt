cmake_minimum_required(VERSION 3.17)
project(CSFMLTest C)

set(CMAKE_C_STANDARD 11)

add_executable(CSFMLTest main.c)

if (WIN32)
        include_directories(${SFML_INCLUDE_DIR} "${PROJECT_SOURCE_DIR}/include")
        add_library(Lib STATIC IMPORTED)
        set_property(TARGET Lib PROPERTY IMPORTED_LOCATION "${PROJECT_SOURCE_DIR}/csfml-graphics-2.dll")
        set_property(TARGET Lib PROPERTY IMPORTED_IMPLIB "${PROJECT_SOURCE_DIR}/lib/gcc/csfml-graphics.a")
        target_link_libraries(CSFMLTest Lib)
else()
    find_package(SFML 2.5 REQUIRED system window graphics network audio)
    target_link_libraries(CSFMLTest csfml-graphics)
endif()

