cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)
project(libQxt)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
include(QtCommon)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)

if (QT_DIR AND NOT Qt${QT_VERSION_MAJOR}_DIR)
	set(Qt${QT_VERSION_MAJOR}_DIR ${QT_DIR} CACHE PATH "Qt directory" FORCE)
endif()

find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets)

INCLUDE_DIRECTORIES(${QT_INCLUDE_DIR})

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/libqxt/lib)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/libqxt/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/libqxt/lib)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/libqxt/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/libqxt/lib)

add_subdirectory( ${CMAKE_SOURCE_DIR}/libqxt/src/core/  ${CMAKE_BINARY_DIR}/qxt-core )


#add_subdirectory( ${CMAKE_SOURCE_DIR}/libqxt/src/gui/  ${CMAKE_BINARY_DIR}/qxt-gui )
#add_dependencies(QxtGui QxtCore)

#add_subdirectory( ${CMAKE_SOURCE_DIR}/libqxt/src/sql/  ${CMAKE_BINARY_DIR}/qxt-sql )
#add_dependencies(QxtSql QxtCore)

#add_subdirectory( ${CMAKE_SOURCE_DIR}/libqxt/src/network/  ${CMAKE_BINARY_DIR}/qxt-network )
#add_dependencies(QxtNetwork QxtCore)
