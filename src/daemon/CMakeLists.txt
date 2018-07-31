#chain daemon module CmakeLists.txt

set(DEAMON_DEPENDS_LIB ssl crypto)

# -- chain_chaind -- #
set(BIN_CHAIN_ID chaind)

add_executable(${BIN_CHAIN_ID} ./chain/main.cpp)


IF (${OS_NAME} MATCHES "OS_LINUX")  
    MESSAGE(STATUS "current platform: Linux ")  
	target_link_libraries(${BIN_CHAIN_ID} -Wl,-dn ${DEAMON_DEPENDS_LIB} ${CHAIN_LINKER_FLAGS})
ELSE ()  
	MESSAGE(STATUS "current platform: MAC ")  
	target_link_libraries(${BIN_CHAIN_ID} -Wl, ${DEAMON_DEPENDS_LIB} ${CHAIN_LINKER_FLAGS})
ENDIF () 



target_compile_options(${BIN_CHAIN_ID}
    PUBLIC -std=c++11
    PUBLIC -D${OS_NAME}
)

install(TARGETS ${BIN_CHAIN_ID}
    RUNTIME DESTINATION ${CHAINCHAIN}/bin
)

