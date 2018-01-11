add_koan(strings)
if(MSVC)
    target_compile_definitions(strings PRIVATE _SCL_SECURE_NO_WARNINGS)
endif()
