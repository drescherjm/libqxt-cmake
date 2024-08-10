
# Qxt Core 

set(LOCAL_TARGET_QT_MODULES Core Gui)

if (${QT_VERSION_MAJOR} EQUAL "6") 
	set(LOCAL_TARGET_QT_MODULES ${LOCAL_TARGET_QT_MODULES} Core5Compat)
endif()


find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS ${LOCAL_TARGET_QT_MODULES})



set(QXT_MOD Core)
STRING(TOUPPER ${QXT_MOD} U_MOD)

include(files.cmake)

set(LOCAL_TARGET_NAME Qxt${QXT_MOD})

add_library(${LOCAL_TARGET_NAME} SHARED ${qxt_headers} ${qxt_sources})

# The following compile definition is used to trigger __declspec(dllexport) versus __declspec(dllimport) on windows 
target_compile_definitions(${LOCAL_TARGET_NAME} PRIVATE -DBUILD_QXT_${U_MOD}) 

setup_naming_convention(${LOCAL_TARGET_NAME})
	 
target_link_libraries(${LOCAL_TARGET_NAME}  PUBLIC Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui)	

target_include_directories(${LOCAL_TARGET_NAME} PUBLIC
	$<INSTALL_INTERFACE:Include> 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
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

file(GLOB qxt_extra_headers ${PROJECT_SOURCE_DIR}/libqxt/include/QxtCore/*)
install (FILES ${qxt_headers} ${qxt_extra_headers} DESTINATION Include)

