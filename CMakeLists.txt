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

SET (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin CACHE INTERNAL "Single output directory for building all libraries.")
SET (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin CACHE INTERNAL "Single output directory for building all executables.")
SET (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin CACHE INTERNAL "Single output directory for building all executables.")

macro( setup_naming_convention TargetName )
	set_target_properties(${TargetName} PROPERTIES DEBUG_POSTFIX d)		
	set_target_properties(${TargetName} PROPERTIES RELWITHDEBINFO_POSTFIX rd)	
	set_target_properties(${TargetName} PROPERTIES MINSIZEREL_POSTFIX rms)
endmacro()

add_subdirectory( ${CMAKE_SOURCE_DIR}/libqxt/src/core/  ${CMAKE_BINARY_DIR}/qxt-core )

add_subdirectory( ${CMAKE_SOURCE_DIR}/libqxt/src/gui/  ${CMAKE_BINARY_DIR}/qxt-gui )
add_dependencies(QxtGui QxtCore)

#add_subdirectory( ${CMAKE_SOURCE_DIR}/libqxt/src/sql/  ${CMAKE_BINARY_DIR}/qxt-sql )
#add_dependencies(QxtSql QxtCore)

#add_subdirectory( ${CMAKE_SOURCE_DIR}/libqxt/src/network/  ${CMAKE_BINARY_DIR}/qxt-network )
#add_dependencies(QxtNetwork QxtCore)

install(EXPORT ${PROJECT_NAME}Targets
        FILE ${PROJECT_NAME}.cmake
        NAMESPACE Qxt::
        DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake/libqxt
)
