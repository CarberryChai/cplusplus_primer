file(GLOB SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

foreach (sourcefile ${SOURCES})
    string(REPLACE ".cpp" "" name ${sourcefile})
    if (${name} EQUAL "Sales_data")
        continue()
    endif ()
    add_executable(${name} ${sourcefile} Sales_data.cpp)
    set_target_properties(${name} PROPERTIES LINKER_LANGUAGE CXX)
endforeach (sourcefile ${SOURCES})