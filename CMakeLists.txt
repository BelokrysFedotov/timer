project(ZTimer C)
cmake_minimum_required(VERSION 2.6)

# включить вывод при сборке
SET( CMAKE_VERBOSE_MAKEFILE on )

# вывести данные о системе
message(STATUS "System: " ${CMAKE_SYSTEM_NAME} " " ${CMAKE_SYSTEM_VERSION})
message(STATUS "Processor: " ${CMAKE_HOST_SYSTEM_PROCESSOR})

# ввывести информацию о компиляторе
if(${CMAKE_SYSTEM_NAME} STREQUAL Windows)
if(MSVC)
message(STATUS "Compiler: MSVC, version: " ${MSVC_VERSION})
endif(MSVC)
if(BORLAND) 
message(STATUS "Compiler: BCC") 
endif(BORLAND) 
else(${CMAKE_SYSTEM_NAME} STREQUAL Linux) 
message(STATUS "Only GCC is supported on Linux")
endif(${CMAKE_SYSTEM_NAME} STREQUAL Windows) 

# тип сборки
message(STATUS "CMake generates " ${CMAKE_GENERATOR})

# установка путей

set(SRC_PATH src/)
set(LIB_PATH lib/)
set(BIN_PATH bin/)

set(PROGRAMS test_z_timer)
set(LIBS z_timer)

include_directories(${SRC_PATH})

foreach(lib ${LIBS})
	add_library(${lib} STATIC ${SRC_PATH}${lib}.c ${SRC_PATH}${lib}.h)
endforeach(lib)

foreach(program ${PROGRAMS})
	add_executable(${program} ${SRC_PATH}/${program}.c)
	#target_link_libraries(${program} ${CORELIBS})
endforeach(program)

message(STATUS "\n\n")

set(CMAKE_C_FLAGS "-g -Wall")
