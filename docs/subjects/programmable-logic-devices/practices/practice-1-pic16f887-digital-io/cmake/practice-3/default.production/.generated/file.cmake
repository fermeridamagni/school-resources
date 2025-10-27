# The following variables contains the files used by the different stages of the build process.
set(practice_3_default_default_XC8_FILE_TYPE_assemble)
set_source_files_properties(${practice_3_default_default_XC8_FILE_TYPE_assemble} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${practice_3_default_default_XC8_FILE_TYPE_assemble})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(practice_3_default_default_XC8_FILE_TYPE_assemblePreprocess)
set_source_files_properties(${practice_3_default_default_XC8_FILE_TYPE_assemblePreprocess} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${practice_3_default_default_XC8_FILE_TYPE_assemblePreprocess})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(practice_3_default_default_XC8_FILE_TYPE_compile "${CMAKE_CURRENT_SOURCE_DIR}/../../../main.c")
set_source_files_properties(${practice_3_default_default_XC8_FILE_TYPE_compile} PROPERTIES LANGUAGE C)
set(practice_3_default_default_XC8_FILE_TYPE_link)
set(practice_3_default_image_name "default-production.elf")
set(practice_3_default_image_base_name "default-production")


# The output directory of the final image.
set(practice_3_default_output_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../../out/practice-3/production")
