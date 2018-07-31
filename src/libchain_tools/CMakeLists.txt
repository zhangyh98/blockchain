#chain tools module CmakeLists.txt -- libchaintools.so

set(LIB_CHAIN_TOOLS chaintools)
set(TOOLS_SRC
    lib_chain_tools.cpp
)

set(INNER_TOOLS_LIBS chain_common chain_utils chain_ed25519)
set(CHAIN_TOOLS_DEPENDS_LIBS json ssl crypto scrypt)


#Generate share library files
add_library(${LIB_CHAIN_TOOLS} SHARED ${TOOLS_SRC}) 

target_link_libraries(${LIB_CHAIN_TOOLS} ${INNER_TOOLS_LIBS} ${CHAIN_TOOLS_DEPENDS_LIBS})

#Specify compiling options for target objects
target_compile_options(${LIB_CHAIN_TOOLS}
    PUBLIC -std=c++11 
    PUBLIC -DASIO_STANDALONE
    PUBLIC -D_WEBSOCKETPP_CPP11_STL_
    PUBLIC -D${OS_NAME}
)
