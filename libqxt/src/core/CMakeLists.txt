
# Qxt Core 

set(QXT_MOD Core)
STRING(TOUPPER ${QXT_MOD} U_MOD)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})


include(files.cmake)


set(current_target Qxt${QXT_MOD})

add_library(${current_target}  SHARED 	 ${qxt_headers} ${qxt_sources})
target_compile_definitions(${current_target} PUBLIC -DBUILD_QXT_${U_MOD}) 
set_target_properties(${current_target} PROPERTIES DEBUG_POSTFIX d)			 
target_link_libraries(${current_target}   Qt5::Core Qt5::Gui )	
		
		
		
		
		
		
		