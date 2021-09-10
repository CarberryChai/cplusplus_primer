list(APPEND SOURCES exercise12_6.cpp exercise12_7.cpp exercise12_20.cpp exercise12_26.cpp)

foreach (sourcefile ${SOURCES})
    string(REPLACE ".cpp" "" name ${sourcefile})
    add_executable(${name} ${sourcefile} StrBlob.cpp StrBlobPtr.cpp)
    set_target_properties(${name} PROPERTIES LINKER_LANGUAGE CXX)
endforeach (sourcefile ${SOURCES})