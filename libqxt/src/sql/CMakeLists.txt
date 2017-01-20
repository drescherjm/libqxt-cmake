
# Qxt SQL 

find_package(Qt5Sql REQUIRED)
set(QXT_MOD Sql)
STRING(TOUPPER ${QXT_MOD} U_MOD)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../core)

find_library(my_lib_name QxtCore PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../../lib/ NO_DEFAULT_PATH)
set(QXT_CORE_LIB  ${my_lib_name})
unset(my_lib_name CACHE)

set(QXT_LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../lib)
set(QXT_CORE_LIB debug ${QXT_LIB_PATH}/QxtCored.lib optimized ${QXT_LIB_PATH}/QxtCore.lib)
		
include(files.cmake)

		
set(current_target Qxt${QXT_MOD})

add_library(${current_target}  SHARED 	 ${qxt_headers} ${qxt_sources})
target_compile_definitions(${current_target} PUBLIC -DBUILD_QXT_${U_MOD}) 
set_target_properties(${current_target} PROPERTIES DEBUG_POSTFIX d)			 
target_link_libraries(${current_target}   Qt5::Sql ${QXT_CORE_LIB})	
		
		
		
		
		
		
		