set(s3d_lib_files matrix.cpp shader.cpp indexed_list.cpp utils.cpp)

add_library(s3d SHARED ${s3d_lib_files})

file(GLOB files "*.hpp")

install(DIRECTORY src/ DESTINATION include/s3d
          FILES_MATCHING PATTERN "*.hpp")
