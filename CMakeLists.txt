cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(libQxt)

set (CMAKE_PREFIX_PATH "G:/Qt/Qt5.2.0/5.2.0/msvc2012")


set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)


set(CMAKE_INCLUDE_CURRENT_DIR ON)
include(QtCommon)
find_package(Qt5Widgets REQUIRED)

# find_package(Qt5Network REQUIRED)
# find_package(Qt5Multimedia REQUIRED)
# find_package(Qt5PrintSupport REQUIRED)

FIND_PACKAGE(Qt5 COMPONENTS  Core Gui  REQUIRED )

INCLUDE_DIRECTORIES(${QT_INCLUDE_DIR})


# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/libqxt/lib)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/libqxt/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/libqxt/lib)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/libqxt/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/libqxt/lib)


add_subdirectory( ${CMAKE_SOURCE_DIR}/libqxt/src/core/  ${CMAKE_BINARY_DIR}/qxt-core )


add_subdirectory( ${CMAKE_SOURCE_DIR}/libqxt/src/gui/  ${CMAKE_BINARY_DIR}/qxt-gui )
add_dependencies(QxtGui QxtCore)

add_subdirectory( ${CMAKE_SOURCE_DIR}/libqxt/src/sql/  ${CMAKE_BINARY_DIR}/qxt-sql )
add_dependencies(QxtSql QxtCore)

add_subdirectory( ${CMAKE_SOURCE_DIR}/libqxt/src/network/  ${CMAKE_BINARY_DIR}/qxt-network )
add_dependencies(QxtNetwork QxtCore)







