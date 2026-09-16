cmake_minimum_required(VERSION 3.23)
project(desperadoo)
set(CMAKE_CXX_STANDARD 23)
add_library(detours STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Detours/src/creatwth.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Detours/src/detours.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Detours/src/disasm.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Detours/src/image.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Detours/src/modules.cpp
)
target_include_directories(detours PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Detours/src
)
add_library(desperadoo SHARED desperadoo.cpp)
target_include_directories(desperadoo PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/Detours/src
)
set_target_properties(desperadoo PROPERTIES
    OUTPUT_NAME "version"
)
target_link_libraries(desperadoo PRIVATE
    detours
)