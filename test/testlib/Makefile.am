PROTOBUF := $(top_builddir)/src/3rd/protobuf/src/.libs/libprotobuf.a
PROTOBUF_PATH := $(top_builddir)/src/3rd/protobuf

ROCKSDB := $(top_builddir)/src/3rd/rocksdb/librocksdb.a
ROCKSDB_PATH := $(top_builddir)/src/3rd/rocksdb

SQLITE3 := $(top_builddir)/src/3rd/sqlite/sqlite3.o
SQLITE3_PATH := $(top_builddir)/src/3rd/sqlite

noinst_PROGRAMS = chain_test

chain_test_SOURCES = test.cpp test_json.cpp test_sqlite.cpp
chain_test_CXXFLAGS = -std=c++11 -DASIO_STANDALONE	\
					-I$(top_builddir)/src/3rd/rocksdb/include	\
					-I$(top_builddir)/src/3rd/sqlite \
					-I$(top_srcdir)/src/3rd/asio/include \
					$(NULL)

chain_test_LDADD =  \
					$(top_builddir)/src/keygen/libchain_keygen.a \
					$(top_builddir)/src/utils/libchain_utils.a \
					-lcrypto -lssl -lpthread -lz -lrt -ldl \
					$(SQLITE3) \
					$(top_builddir)/src/3rd/jsoncpp/libs/linux-gcc-4.9.2/libjson_linux-gcc-4.9.2_libmt.a \
					$(NULL)
INCLUDES=-I$(top_srcdir)/src \
	 -I$(top_builddir)/src/3rd/jsoncpp/include/
