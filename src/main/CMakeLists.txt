#chain main module CmakeLists.txt -- chain

set(APP_CHAIN chain)

set(APP_CHAIN_SRC
    main.cpp
    configure.cpp
    ../api/web_server.cpp
    ../api/web_server_query.cpp
    ../api/web_server_update.cpp
    ../api/web_server_command.cpp
    ../api/web_server_helper.cpp
    ../api/websocket_server.cpp
    ../api/console.cpp
)

set(INNER_LIBS chain_glue chain_ledger chain_consensus chain_overlay chain_common chain_utils chain_proto chain_http chain_ed25519 chain_monitor)
set(V8_LIBS v8_base v8_libbase v8_external_snapshot v8_libplatform v8_libsampler icui18n icuuc inspector)

#Generate executable files
add_executable(${APP_CHAIN} ${APP_CHAIN_SRC})

#Specify dependent libraries for target objects
	
IF (${OS_NAME} MATCHES "OS_LINUX")  
    MESSAGE(STATUS "current platform: Linux ")  
	target_link_libraries(${APP_CHAIN}
    -Wl,-dn ${INNER_LIBS} -Wl,--start-group ${V8_LIBS} -Wl,--end-group ${CHAIN_DEPENDS_LIBS} ${CHAIN_LINKER_FLAGS})
ELSE ()  
	MESSAGE(STATUS "current platform: MAC ")  
	add_definitions(${CHAIN_LINKER_FLAGS})
	target_link_libraries(${APP_CHAIN} ${INNER_LIBS} ${V8_LIBS} ${CHAIN_DEPENDS_LIBS})
ENDIF () 


#Specify compiling options for target objets
target_compile_options(${APP_CHAIN}
    PUBLIC -std=c++11 
    PUBLIC -DASIO_STANDALONE
    PUBLIC -D_WEBSOCKETPP_CPP11_STL_
    PUBLIC -D${OS_NAME}
)

install(TARGETS ${APP_CHAIN}
    RUNTIME DESTINATION ${CHAINCHAIN}/bin
)
