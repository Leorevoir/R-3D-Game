########################################

set(R_GWENT_TARGET_NAME r-gwent)

########################################

add_executable(${R_GWENT_TARGET_NAME} ${SRC_R_GAME})
target_include_directories(${R_GWENT_TARGET_NAME} PRIVATE ${INCLUDE_R_GAME})
target_link_libraries(${R_GWENT_TARGET_NAME} PRIVATE r-engine)

########################################
