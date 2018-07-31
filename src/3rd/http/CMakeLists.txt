#chain http module CmakeLists.txt -- libchain_http.a

set(LIB_CHAIN_HTTP chain_http)
aux_source_directory(${CHAIN_SRC_DIR}/3rd/http/ HTTP_SRC)

add_library(${LIB_CHAIN_HTTP} ${HTTP_SRC})

target_compile_options(${LIB_CHAIN_HTTP}
    PUBLIC -std=c++11 
    PUBLIC -DASIO_STANDALONE
    PUBLIC -D${OS_NAME}
)
