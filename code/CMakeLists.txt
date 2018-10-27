cmake_minimum_required(VERSION 2.8)

project(renderer)

# Silence warnings about deprecated GLUT functions
if(APPLE)
    add_definitions("-Wno-deprecated-declarations")
endif()

if(UNIX)
    # Enable C++11
    add_definitions("-std=c++11")
elseif(MSVC)
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -WX")
  add_definitions("-D_CRT_SECURE_NO_WARNINGS")
endif()

include_directories(src/)

set (SRC_DIR "src/")

set(CPP_FILES
    ${SRC_DIR}/main/main.cpp
    ${SRC_DIR}/linalg/Vector2.cpp
    ${SRC_DIR}/linalg/Vector3.cpp
    ${SRC_DIR}/linalg/Matrix3x3.cpp
    )

set(CPP_HEADERS
    ${SRC_DIR}/linalg/Vector2.h
    ${SRC_DIR}/linalg/Vector3.h
    ${SRC_DIR}/linalg/Matrix3x3.h
    )


add_executable(renderer ${CPP_FILES} ${CPP_HEADERS})
target_link_libraries(renderer)

