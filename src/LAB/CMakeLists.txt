set(MODULE_NAME LAB)
message("LAB " ${MODULE_NAME})

file(GLOB_RECURSE SOURCES *.h *.cpp *.hpp)
add_library(${MODULE_NAME} STATIC ${SOURCES})

set_target_properties(LAB PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(${MODULE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
