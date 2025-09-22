
# Qxt Gui 

set(LOCAL_TARGET_QT_MODULES Core Gui Widgets)

if (${QT_VERSION_MAJOR} EQUAL "6") 
	set(LOCAL_TARGET_QT_MODULES ${LOCAL_TARGET_QT_MODULES} Core5Compat)
endif()

find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS ${LOCAL_TARGET_QT_MODULES})

set(QXT_MOD Gui)
STRING(TOUPPER ${QXT_MOD} U_MOD)

include(files.cmake)
		
set(LOCAL_TARGET_NAME Qxt${QXT_MOD})

add_library(${LOCAL_TARGET_NAME}  SHARED ${qxt_headers} ${qxt_sources})
target_compile_definitions(${LOCAL_TARGET_NAME} PRIVATE -DBUILD_QXT_${U_MOD}) 

setup_naming_convention(${LOCAL_TARGET_NAME})
		
foreach(module IN LISTS LOCAL_TARGET_QT_MODULES)
    target_link_libraries(${LOCAL_TARGET_NAME} PUBLIC Qt${QT_VERSION_MAJOR}::${module})
endforeach()

target_link_libraries(${LOCAL_TARGET_NAME} PUBLIC QxtCore)

target_include_directories(${LOCAL_TARGET_NAME} PUBLIC
	$<INSTALL_INTERFACE:Include> 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../core>
)

install(TARGETS ${LOCAL_TARGET_NAME}
    EXPORT ${PROJECT_NAME}Targets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

#message(STATUS qxt_headers=${qxt_headers})

#Remove the private implementations from the headers list.
list(FILTER qxt_headers EXCLUDE REGEX "^.+_p\.h$")
#message(FATAL_ERROR qxt_headers=${qxt_headers})

file(GLOB qxt_extra_headers ${PROJECT_SOURCE_DIR}/libqxt/include/Qxt${QXT_MOD}/*)
install (FILES ${qxt_headers} ${qxt_extra_headers} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

		
		
		
		
		
		