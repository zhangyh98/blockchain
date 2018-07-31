cmake_minimum_required(VERSION 2.8)

project(chain)
add_compile_options(-g -O2)
add_definitions(-DSVNVERSION=\"${SVNVERSION}\")
message(STATUS "-DSVNVERSION="${SVNVERSION})

set( V8_LIB_PATH "linux")
set( OS_NAME "OS_LINUX")
IF (CMAKE_SYSTEM_NAME MATCHES "Linux")  
    MESSAGE(STATUS "current platform: Linux ")  
	set( OS_NAME "OS_LINUX")
	set(CHAIN_LINKER_FLAGS "-Wl,-dy -lpthread -lrt -ldl")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")  
    MESSAGE(STATUS "current platform: Darwin")  
	set( OS_NAME "OS_MAC")
	set(CHAIN_LINKER_FLAGS "-Wl, -lpthread -ldl")
	set( V8_LIB_PATH "mac")
ELSE ()  
    MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")  
ENDIF ()  

set(CHAINCHAIN buchain)
set(CHAIN_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CHAIN_ROOT_DIR ${CHAIN_SRC_DIR}/..)
set(LIBRARY_OUTPUT_PATH ${CHAIN_ROOT_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${CHAIN_ROOT_DIR}/bin)

set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS)
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS)

execute_process(COMMAND make all WORKING_DIRECTORY ${CHAIN_SRC_DIR}/3rd)

include_directories(
    ${CHAIN_SRC_DIR}
    ${CHAIN_SRC_DIR}/3rd/basic/include/v8
    ${CHAIN_SRC_DIR}/3rd/protobuf/src
    ${CHAIN_SRC_DIR}/3rd/jsoncpp/include
    ${CHAIN_SRC_DIR}/3rd/sqlite 
    ${CHAIN_SRC_DIR}/3rd/rocksdb/include
    ${CHAIN_SRC_DIR}/3rd/pcre-8.39
    ${CHAIN_SRC_DIR}/3rd/websocketpp
    ${CHAIN_SRC_DIR}/3rd/bzip2-1.0.6
    ${CHAIN_SRC_DIR}/3rd/zlib-1.2.8
    ${CHAIN_SRC_DIR}/3rd/asio/include
    ${CHAIN_SRC_DIR}/3rd/openssl/include
    ${CHAIN_SRC_DIR}/3rd/http
    ${CHAIN_SRC_DIR}/3rd/libscrypt
)

link_directories(
    ${CHAIN_SRC_DIR}/3rd/protobuf/src/.libs
    ${CHAIN_SRC_DIR}/3rd/rocksdb
    ${CHAIN_SRC_DIR}/3rd/pcre-8.39/.libs
    ${CHAIN_SRC_DIR}/3rd/jsoncpp/libs
    ${CHAIN_SRC_DIR}/3rd/openssl
    ${CHAIN_SRC_DIR}/3rd/zlib-1.2.8
    ${CHAIN_SRC_DIR}/3rd/libscrypt
    ${CHAIN_SRC_DIR}/3rd/bzip2-1.0.6
    ${CHAIN_SRC_DIR}/3rd/basic/lib
    ${CHAIN_SRC_DIR}/3rd/curl/lib/.libs/
    ${CHAIN_SRC_DIR}/3rd/v8_target/${V8_LIB_PATH}/
    ${LIBRARY_OUTPUT_PATH}
)

set(CHAIN_DEPENDS_LIBS protobuf rocksdb pcreposix pcrecpp pcre json ssl crypto z bz2 scrypt)

add_subdirectory(3rd/http)
add_subdirectory(3rd/ed25519-donna)
add_subdirectory(glue)
add_subdirectory(utils)
add_subdirectory(proto)
add_subdirectory(ledger)
add_subdirectory(common)
add_subdirectory(libchain_tools)
add_subdirectory(overlay)
add_subdirectory(consensus)
add_subdirectory(daemon)
add_subdirectory(monitor)
add_subdirectory(main)

set(CHAIN_SCRIPTS ${CHAIN_ROOT_DIR}/deploy)
install(
    PROGRAMS ${CHAIN_SCRIPTS}/chain ${CHAIN_SCRIPTS}/chaind ${CHAIN_SCRIPTS}/start-stop-daemon
    DESTINATION ${CHAINCHAIN}/scripts
)

install(
    DIRECTORY ${CHAIN_ROOT_DIR}/bin/
    DESTINATION ${CHAINCHAIN}/bin
    FILES_MATCHING PATTERN "*.bin" PATTERN "*.dat"
)

install(
    DIRECTORY ${CHAIN_ROOT_DIR}/build/win32/config/
    DESTINATION ${CHAINCHAIN}/config
    FILES_MATCHING PATTERN "config.json" PATTERN "config-mainnet.json" PATTERN "config-testnet.json" PATTERN "config-single.json"
)

install(
    DIRECTORY ${CHAIN_ROOT_DIR}/build/win32/jslib/
    DESTINATION ${CHAINCHAIN}/jslib
    FILES_MATCHING PATTERN "*.js"
)

set(SUPPLEMENT ${CHAIN_ROOT_DIR}/build/linux/MakeSupplement)
set(FIX_DIR ${CMAKE_INSTALL_PREFIX}/${CHAINCHAIN})
message(STATUS "install dir: ${FIX_DIR}")

file(WRITE ${SUPPLEMENT} "soft_link:\n")
file(APPEND ${SUPPLEMENT} "\tsudo ln -s ${FIX_DIR}/scripts/chain /etc/init.d/chain;\\\n")
file(APPEND ${SUPPLEMENT} "\tsudo ln -s ${FIX_DIR}/scripts/chaind /etc/init.d/chaind;\\\n")
file(APPEND ${SUPPLEMENT} "\tsudo ln -s -f /etc/init.d/chain /etc/rc1.d/S99chain;\\\n")
file(APPEND ${SUPPLEMENT} "\tsudo ln -s -f /etc/init.d/chain /etc/rc1.d/S99chain;\\\n")
file(APPEND ${SUPPLEMENT} "\tsudo ln -s -f /etc/init.d/chain /etc/rc2.d/S99chain;\\\n")
file(APPEND ${SUPPLEMENT} "\tsudo ln -s -f /etc/init.d/chain /etc/rc3.d/S99chain;\\\n")
file(APPEND ${SUPPLEMENT} "\tsudo ln -s -f /etc/init.d/chain /etc/rc4.d/S99chain;\\\n")
file(APPEND ${SUPPLEMENT} "\tsudo ln -s -f /etc/init.d/chain /etc/rc5.d/S99chain;\\\n")
file(APPEND ${SUPPLEMENT} "\tsudo ln -s -f /etc/init.d/chaind /etc/rc1.d/S50chaind;\\\n")
file(APPEND ${SUPPLEMENT} "\tsudo ln -s -f /etc/init.d/chaind /etc/rc1.d/S50chaind;\\\n")
file(APPEND ${SUPPLEMENT} "\tsudo ln -s -f /etc/init.d/chaind /etc/rc2.d/S50chaind;\\\n")
file(APPEND ${SUPPLEMENT} "\tsudo ln -s -f /etc/init.d/chaind /etc/rc3.d/S50chaind;\\\n")
file(APPEND ${SUPPLEMENT} "\tsudo ln -s -f /etc/init.d/chaind /etc/rc4.d/S50chaind;\\\n")
file(APPEND ${SUPPLEMENT} "\tsudo ln -s -f /etc/init.d/chaind /etc/rc5.d/S50chaind;\\\n")
file(APPEND ${SUPPLEMENT} "\tsudo mkdir -p ${FIX_DIR}/data;\n")
file(APPEND ${SUPPLEMENT} "\tsudo mkdir -p ${FIX_DIR}/coredump;\n")

file(APPEND ${SUPPLEMENT} "\nuninstall:\n")
file(APPEND ${SUPPLEMENT} "\trm -f /etc/rc1.d/S99chain;\\\n")
file(APPEND ${SUPPLEMENT} "\trm -f /etc/rc2.d/S99chain;\\\n")
file(APPEND ${SUPPLEMENT} "\trm -f /etc/rc3.d/S99chain;\\\n")
file(APPEND ${SUPPLEMENT} "\trm -f /etc/rc4.d/S99chain;\\\n")
file(APPEND ${SUPPLEMENT} "\trm -f /etc/rc5.d/S99chain;\\\n")
file(APPEND ${SUPPLEMENT} "\trm -f /etc/init.d/chain;\\\n")
file(APPEND ${SUPPLEMENT} "\trm -f /etc/rc1.d/S50chaind;\\\n")
file(APPEND ${SUPPLEMENT} "\trm -f /etc/rc2.d/S50chaind;\\\n")
file(APPEND ${SUPPLEMENT} "\trm -f /etc/rc3.d/S50chaind;\\\n")
file(APPEND ${SUPPLEMENT} "\trm -f /etc/rc4.d/S50chaind;\\\n")
file(APPEND ${SUPPLEMENT} "\trm -f /etc/rc5.d/S50chaind;\\\n")
file(APPEND ${SUPPLEMENT} "\trm -f /etc/init.d/chaind;\\\n")
file(APPEND ${SUPPLEMENT} "\trm -rf ${FIX_DIR}/bin;\\\n")
file(APPEND ${SUPPLEMENT} "\trm -rf ${FIX_DIR}/cfca;\\\n")
file(APPEND ${SUPPLEMENT} "\trm -rf ${FIX_DIR}/config;\\\n")
file(APPEND ${SUPPLEMENT} "\trm -rf ${FIX_DIR}/scripts\n")
