set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

file(GLOB SHADERS
        "*.vs"
        "*.fs"
        "*.gs"
        "*.jpg"
        "*.bmp"
        "*.obj"
        "*.mtl"
        )
message(STATUS "Begin to copy files ...")
foreach(SHADER ${SHADERS})
#    message(STATUS "current file is: ${SHADER}")
    file(COPY ${SHADER} DESTINATION ${PROJECT_SOURCE_DIR}/bin)
endforeach(SHADER)