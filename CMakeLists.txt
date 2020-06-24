cmake_minimum_required(VERSION 3.1.0)
project(mumlib)

if (NOT APPLE)
	add_definitions(-DOPT_TLS_GNUTLS -D_POSIX_C_SOURCE=200112L)
else()
	LINK_DIRECTORIES(/opt/local/lib) # Include the default MacPorts library directory
endif()

find_package(Boost COMPONENTS system REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Protobuf REQUIRED)

set(MUMLIB_PUBLIC_HEADERS include/mumlib.hpp include/mumlib/VarInt.hpp)

set(MUMLIB_PRIVATE_HEADERS
	include/mumlib/Callback.hpp
	include/mumlib/CryptState.hpp
	include/mumlib/Transport.hpp
	include/mumlib/Audio.hpp
	include/mumlib/enums.hpp
)

set(MUMLIB_SRC
	src/mumlib.cpp
	src/Callback.cpp
	src/CryptState.cpp
	src/VarInt.cpp
	src/Transport.cpp
	src/Audio.cpp
)

set(SPEEX_LIBRARIES
	#speex
	speexdsp
)

PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS Mumble.proto)

add_library(mumlib ${MUMLIB_SRC} ${MUMLIB_PUBLIC_HEADERS} ${MUMLIB_PRIVATE_HEADERS} ${PROTO_SRCS} ${PROTO_HDRS})

target_compile_features(mumlib PUBLIC cxx_std_11)

target_include_directories(mumlib PUBLIC ${Boost_INCLUDE_DIR})
target_include_directories(mumlib PUBLIC ${OPENSSL_INCLUDE_DIR})
target_include_directories(mumlib PUBLIC ${PROTOBUF_INCLUDE_DIRS})

target_include_directories(mumlib PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
target_include_directories(mumlib PRIVATE "include")

target_link_libraries(mumlib
	${SPEEX_LIBRARIES}
	${PROTOBUF_LIBRARIES}
	${Boost_LIBRARIES}
	${OPENSSL_LIBRARIES}
	opus
)

set_target_properties(mumlib PROPERTIES PUBLIC_HEADER "${MUMLIB_PUBLIC_HEADERS}")

add_executable(mumlib_example EXCLUDE_FROM_ALL mumlib_example.cpp)
target_link_libraries(mumlib_example mumlib)

install(TARGETS mumlib LIBRARY DESTINATION lib PUBLIC_HEADER DESTINATION include/mumlib)

