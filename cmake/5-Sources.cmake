#######################################

file(GLOB_RECURSE SRC_R_GAME "src/*.cpp")
if(NOT SRC_R_GAME)
    message(FATAL_ERROR "No source files found under src/ — check path or globs.")
endif()

#######################################

set(INCLUDE_R_GAME
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/external/R-Engine/include"
)

#######################################

message(STATUS "INFO: found ${CMAKE_CURRENT_LIST_DIR}/../src/*.cpp sources")

#######################################
