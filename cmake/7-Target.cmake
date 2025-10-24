########################################

set(R_GAME_TARGET_NAME r-game)

########################################

add_executable(${R_GAME_TARGET_NAME} ${SRC_R_GAME})
target_include_directories(${R_GAME_TARGET_NAME} PRIVATE ${INCLUDE_R_GAME})
target_link_libraries(${R_GAME_TARGET_NAME} PRIVATE r-engine)

########################################
