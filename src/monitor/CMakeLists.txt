#chain monitor module CmakeLists.txt -- libchain_monitor.a
set(LIB_CHAIN_MONITOR chain_monitor)

#Automatically get src files from the specified directory
aux_source_directory(${CHAIN_SRC_DIR}/monitor/ MONITOR_SRC)

#Generate static library files
add_library(${LIB_CHAIN_MONITOR} ${MONITOR_SRC})

#Specify compiling options for the target objects
target_compile_options(${LIB_CHAIN_MONITOR}
    PUBLIC -std=c++11 
    PUBLIC -DASIO_STANDALONE
    PUBLIC -D_WEBSOCKETPP_CPP11_STL_
    PUBLIC -D${OS_NAME}
)
