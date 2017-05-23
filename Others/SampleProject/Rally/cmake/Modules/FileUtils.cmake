# /**
#  *  "GET_CPP_RECURSIVE" is function for GET CPP in current Directory and subfolders when invoke function
#  *
#  * @param[IN]  "DIR_NAME"" is name of director for GET CPP_LIST
#  * @param[OUT]  "CPP_LIST" is return list from CPP FILES in this directory "DIR_NAME"
#  */
MACRO(GET_CPP_RECURSIVE DIR_NAME CPP_LIST)      
      file(GLOB_RECURSE SOURCES "${DIR_NAME}/*.cpp" "${DIR_NAME}/*.hpp" "${DIR_NAME}/*.h" "${DIR_NAME}/*.c")
      list(SORT SOURCES)
      SET(${CPP_LIST} ${SOURCES})
ENDMACRO() 
