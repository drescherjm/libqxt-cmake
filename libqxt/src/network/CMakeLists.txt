
# Qxt NETWORK 

find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network)

set(QXT_MOD Network)
STRING(TOUPPER ${QXT_MOD} U_MOD)

# INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
# INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../core)

# find_library(my_lib_name QxtCore PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../../lib/ NO_DEFAULT_PATH)
# set(QXT_CORE_LIB  ${my_lib_name})
# unset(my_lib_name CACHE)
	
# set(QXT_LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../lib)
# set(QXT_CORE_LIB debug ${QXT_LIB_PATH}/QxtCored.lib optimized ${QXT_LIB_PATH}/QxtCore.lib)
	
include(files.cmake)
		
set(LOCAL_TARGET_NAME Qxt${QXT_MOD})

add_library(${LOCAL_TARGET_NAME}  SHARED ${qxt_headers} ${qxt_sources})
target_compile_definitions(${LOCAL_TARGET_NAME} PUBLIC -DBUILD_QXT_${U_MOD}) 

setup_naming_convention(${LOCAL_TARGET_NAME})
		
target_link_libraries(${LOCAL_TARGET_NAME} PUBLIC Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Network QxtCore)	

target_include_directories(${LOCAL_TARGET_NAME} PUBLIC
	$<INSTALL_INTERFACE:Include> 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../core>
)

install (TARGETS ${LOCAL_TARGET_NAME} DESTINATION lib
        EXPORT ${PROJECT_NAME}Targets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

#message(STATUS qxt_headers=${qxt_headers})

#Remove the private implementations from the headers list.
list(FILTER qxt_headers EXCLUDE REGEX "^.+_p\.h$")
#message(FATAL_ERROR qxt_headers=${qxt_headers})

file(GLOB qxt_extra_headers ${PROJECT_SOURCE_DIR}/libqxt/include/Qxt${QXT_MOD}/*)
install (FILES ${qxt_headers} ${qxt_extra_headers} DESTINATION Include)		