cmake_minimum_required(VERSION 3.0.0)
project(PracticesOfOpenCV VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)

# 添加opencv
find_package(OpenCV REQUIRED)
MESSAGE("${OpenCV_INSTALL_PATH}")
MESSAGE("OpenCV version: ${OpenCV_VERSION}")  # 打印OpenCV版本
MESSAGE("TOP CMakeLists: ${CMAKE_CURRENT_SOURCE_DIR}")
MESSAGE("OpenCV Include Dir: ${OpenCV_INCLUDE_DIRS}")

# 添加源文件目录
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SOURCES)

# 添加子目录
add_subdirectory(./utils)

#添加头文件路径
include_directories( ${OpenCV_INCLUDE_DIRS})
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/inc)

#添加库依赖路径
link_directories( ${OpenCV_LIB_DIR})

#添加库文件
link_libraries( ${OpenCV_LIBS} Utils)

# add_executable(PracticesOfOpenCV ${SOURCES})
add_executable(ReadWriteImgs ${CMAKE_CURRENT_SOURCE_DIR}/src/read_write_imgs.cpp)
add_executable(ReadCamera ${CMAKE_CURRENT_SOURCE_DIR}/src/read_camera.cpp)
# target_include_directories(ReadWriteImgs PRIVATE ${OpenCV_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/inc)
# target_link_directories(ReadWriteImgs PRIVATE ${OpenCV_LIB_DIR})
# target_link_libraries(ReadWriteImgs PRIVATE ${OpenCV_LIBS} Utils)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
