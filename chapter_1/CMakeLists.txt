file(GLOB SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

foreach (sourcefile ${SOURCES})
    string(REPLACE ".cpp" "" name ${sourcefile})
    add_executable(${name} ${sourcefile})
    set_target_properties(${name} PROPERTIES LINKER_LANGUAGE CXX)
    target_link_libraries(${name} Sales_item)
endforeach (sourcefile ${SOURCES})