file(GLOB SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

foreach (sourcefile ${SOURCES})
    string(REPLACE ".cpp" "" name ${sourcefile})
    FILE(COPY test.txt DESTINATION "${CMAKE_BINARY_DIR}/chapter_8")
    add_executable(${name} ${sourcefile} ../chapter_7/Sales_data.cpp)
    set_target_properties(${name} PROPERTIES LINKER_LANGUAGE CXX)
endforeach (sourcefile ${SOURCES})