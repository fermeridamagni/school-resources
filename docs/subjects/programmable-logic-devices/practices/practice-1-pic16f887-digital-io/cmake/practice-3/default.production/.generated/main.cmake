# cmake files support debug production
include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(practice_3_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(practice_3_default_default_XC8_FILE_TYPE_assemble)
add_library(practice_3_default_default_XC8_assemble OBJECT ${practice_3_default_default_XC8_FILE_TYPE_assemble})
    practice_3_default_default_XC8_assemble_rule(practice_3_default_default_XC8_assemble)
    list(APPEND practice_3_default_library_list "$<TARGET_OBJECTS:practice_3_default_default_XC8_assemble>")
endif()

# Handle files with suffix S, for group default-XC8
if(practice_3_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(practice_3_default_default_XC8_assemblePreprocess OBJECT ${practice_3_default_default_XC8_FILE_TYPE_assemblePreprocess})
    practice_3_default_default_XC8_assemblePreprocess_rule(practice_3_default_default_XC8_assemblePreprocess)
    list(APPEND practice_3_default_library_list "$<TARGET_OBJECTS:practice_3_default_default_XC8_assemblePreprocess>")
endif()

# Handle files with suffix [cC], for group default-XC8
if(practice_3_default_default_XC8_FILE_TYPE_compile)
add_library(practice_3_default_default_XC8_compile OBJECT ${practice_3_default_default_XC8_FILE_TYPE_compile})
    practice_3_default_default_XC8_compile_rule(practice_3_default_default_XC8_compile)
    list(APPEND practice_3_default_library_list "$<TARGET_OBJECTS:practice_3_default_default_XC8_compile>")
endif()


add_executable(practice_3_default_image_GezPIjMM ${practice_3_default_library_list})

set_target_properties(practice_3_default_image_GezPIjMM PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${practice_3_default_output_dir})
set_target_properties(practice_3_default_image_GezPIjMM PROPERTIES OUTPUT_NAME "default-production")
set_target_properties(practice_3_default_image_GezPIjMM PROPERTIES SUFFIX ".elf")
         

target_link_libraries(practice_3_default_image_GezPIjMM PRIVATE ${practice_3_default_default_XC8_FILE_TYPE_link})


# Add the link options from the rule file.
practice_3_default_link_rule(practice_3_default_image_GezPIjMM)




