cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)

#required args:
#arg0: target file
#arg1: the glsl file
function(Convert_glsl args)
    list(LENGTH ARGV arg_len)
    if(${arg_len} LESS 2)
        message(WARNING "the number of args less 2!")
    elseif(NOT EXISTS ${ARGV1})
        message(WARNING "the glsl file not exist!")
    else()
        cvt_glsl_impl(${ARGV})
    endif()
endfunction()

function(cvt_glsl_impl args)
    message(STATUS "ARGN: ${ARGN}")
    message(STATUS "ARGC: ${ARGC}")
    message(STATUS "ARGV: ${ARGV}")
    message(STATUS "ARGV0: ${ARGV0}")

    set(_MY_H_DEF_ "CONVERT_GLSL_GEN_BY_CMAKE_H_")

    set(AB_OUT_TARGET_FILENAME ${ARGV0})
    set(AB_TARGET_GLSL_FILENAME ${ARGV1})
    get_filename_component(T_FILENAME ${ARGV1} NAME)
    get_filename_component(T_FILENAME_WE ${ARGV1} NAME_WE)
    string(REPLACE "." "_" CHECKED_FILENAME ${T_FILENAME})
##for debug
#    message(STATUS "T_FILENAME is: ${T_FILENAME}")
#    message(STATUS "T_FILENAME_WE is: ${T_FILENAME_WE}")
#    message(STATUS "CHECKED_FILENAME is: ${CHECKED_FILENAME}")

    set(_M_H_STRING_ "const char  ${CHECKED_FILENAME}[]=")

    string(TIMESTAMP TODAY "%Y-%m-%d")

    file(WRITE ${AB_OUT_TARGET_FILENAME} "//Created on ${TODAY}\n\n")
    file(APPEND ${AB_OUT_TARGET_FILENAME} "#ifndef ${_MY_H_DEF_}\n#define ${_MY_H_DEF_}\n\n")

    #遍历目标文件所有行
    file(APPEND ${AB_OUT_TARGET_FILENAME} "${_M_H_STRING_}\n")
    file(STRINGS ${AB_TARGET_GLSL_FILENAME} OUTLINE)
    foreach(item ${OUTLINE})
        #message(STATUS "----"${item})
        string(LENGTH ${item} CUREENT_LINE_LENGTH)
        math(EXPR MHH 90-${CUREENT_LINE_LENGTH})

        file(APPEND ${AB_OUT_TARGET_FILENAME} "\t\t\"${item}")
        foreach(idx RANGE ${MHH})
            file(APPEND ${AB_OUT_TARGET_FILENAME} " ")
        endforeach()
        file(APPEND ${AB_OUT_TARGET_FILENAME} "\\n\"\n")
    endforeach()
    file(APPEND ${AB_OUT_TARGET_FILENAME} ";\n\n")

    file(APPEND ${AB_OUT_TARGET_FILENAME} "#endif //${_MY_H_DEF_}\n")

endfunction()