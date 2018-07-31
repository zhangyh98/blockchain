#chain ed25519 module CmakeLists.txt -- libchain_ed25519.a

set(LIB_CHAIN_ED25519 chain_ed25519)
aux_source_directory(${CHAIN_SRC_DIR}/3rd/ed25519-donna/ ED25519_SRC)
add_library(${LIB_CHAIN_ED25519} ${ED25519_SRC}) 

target_compile_options(${LIB_CHAIN_ED25519} 
	PUBLIC -DASIO_STANDALONE 
	PUBLIC -fPIC
)
