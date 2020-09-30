cmake_minimum_required(VERSION 3.17)
project(CSFMLTest C)

set(CMAKE_C_STANDARD 11)

add_executable(CSFMLTest main.c)

find_package(SFML 2.5 REQUIRED system window graphics network audio)
if (SFML_FOUND)
    if (WIN32)
        include_directories(${SFML_INCLUDE_DIR} "${PROJECT_SOURCE_DIR}/include")
        add_library(Lib STATIC IMPORTED)
        set_property(TARGET Lib PROPERTY IMPORTED_LOCATION "${PROJECT_SOURCE_DIR}/csfml-graphics-2.dll")
        set_property(TARGET Lib PROPERTY IMPORTED_IMPLIB "C:/csfml_lib/lib/gcc/csfml-graphics.a")
        target_link_libraries(CSFMLTest Lib)
    else()
        target_link_libraries(CSFMLTest csfml-graphics)
    endif()
endif()

