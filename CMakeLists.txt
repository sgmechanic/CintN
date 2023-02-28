
cmake_minimum_required(VERSION 3.26)

project(CintN)



cmake_minimum_required(VERSION 3.26)

project(CintN)

#aux_source_directory(. SRC_LIST)

set(VECTOR_SRC main.cpp func.cpp func0.cpp func1.cpp autotest.cpp)
set(VECTOR_HDR header.hpp CIntN0.hpp CIntN1.hpp IntFabric.hpp IntFabric0.hpp IntFabric1.hpp autotest.hpp)

#add_executable(${PROJECT_NAME} ${SRC_LIST})
#add_library(vector STATIC ${VECTOR_SRC} ${VECTOR_HDR})
add_executable(${PROJECT_NAME} ${VECTOR_SRC} ${VECTOR_HDR})

#target_link_libraries(${PROJECT_NAME} vector)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")