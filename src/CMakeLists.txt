file(GLOB s3d_lib_files *.cpp)

add_library(s3d SHARED ${s3d_lib_files})

add_library(s3d_static STATIC ${s3d_lib_files})
set_target_properties(s3d_static PROPERTIES OUTPUT_NAME s3d)