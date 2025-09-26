cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

include(cmake/SupportSwitchingQtVersionAsAFeature.cmake)

project(libQxt)

set (${PROJECT_NAME}_VERSION_MAJOR 7)
set (${PROJECT_NAME}_VERSION_MINOR 0)
set (${PROJECT_NAME}_VERSION_PATCH 0)
set (${PROJECT_NAME}_VERSION_PATCH_CLEAN ${${PROJECT_NAME}_VERSION_PATCH})
set (${PROJECT_NAME}_VERSION_STRING "${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR}.${${PROJECT_NAME}_VERSION_PATCH}")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
include(QtCommon)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)

include(GNUInstallDirs)

if (QT_DIR AND NOT Qt${QT_VERSION_MAJOR}_DIR)
	set(Qt${QT_VERSION_MAJOR}_DIR ${QT_DIR} CACHE PATH "Qt directory" FORCE)
endif()

SET (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin CACHE INTERNAL "Single output directory for building all libraries.")
SET (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin CACHE INTERNAL "Single output directory for building all executables.")
SET (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin CACHE INTERNAL "Single output directory for building all executables.")

macro( setup_naming_convention TargetName )
	#set_target_properties(${TargetName} "-${PROJECT_NAME}_VERSION_STRING}-r-${PROJECT_COMPILER_VERSION}${ARCH_SUFFIX}")
	#set_target_properties(${TargetName} PROPERTIES RELEASE_POSTFIX "-${PROJECT_NAME}_VERSION_STRING}-r")
	set_target_properties(${TargetName} PROPERTIES DEBUG_POSTFIX d)		
	set_target_properties(${TargetName} PROPERTIES RELWITHDEBINFO_POSTFIX rd)	
	set_target_properties(${TargetName} PROPERTIES MINSIZEREL_POSTFIX rms)
endmacro()

add_subdirectory( ${CMAKE_SOURCE_DIR}/libqxt/src/core/  ${CMAKE_BINARY_DIR}/qxt-core )

option (BUILD_QXT_GUI 	"Build QxtGui" ON)
if (BUILD_QXT_GUI)
	add_subdirectory( ${CMAKE_SOURCE_DIR}/libqxt/src/gui/  ${CMAKE_BINARY_DIR}/qxt-gui )
	add_dependencies(QxtGui QxtCore)
endif()

option (BUILD_QXT_SQL 	"Build QxtSql" OFF)

if (BUILD_QXT_SQL)
	add_subdirectory( ${CMAKE_SOURCE_DIR}/libqxt/src/sql/  ${CMAKE_BINARY_DIR}/qxt-sql )
	add_dependencies(QxtSql QxtCore)
endif()

option (BUILD_QXT_NETWORK 	"Build QxtNetwork" OFF)
if (BUILD_QXT_NETWORK)
	add_subdirectory( ${CMAKE_SOURCE_DIR}/libqxt/src/network/  ${CMAKE_BINARY_DIR}/qxt-network )
	add_dependencies(QxtNetwork QxtCore)
endif()

#########################################################################################
# This section is essential for the dependent library targets to be properly exported
# for vcpkg to consume the library target(s) for this project.

include(CMakePackageConfigHelpers)

# Export all targets
install(EXPORT ${PROJECT_NAME}Targets
    FILE ${PROJECT_NAME}Targets.cmake
    NAMESPACE Qxt:: # Give each library a namespace which will create an alias library
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

# Generate and install the Config file
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)


#########################################################################################
