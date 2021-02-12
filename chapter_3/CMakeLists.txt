file(GLOB SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

foreach (sourcefile ${SOURCES})
    string(REPLACE ".cpp" "" name ${sourcefile})
    add_executable(${name} ${sourcefile})
endforeach (sourcefile ${SOURCES})