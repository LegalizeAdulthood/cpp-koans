add_koan(string_view)
if(MSVC)
    target_compile_options(string_view PRIVATE /std:c++17)
endif()
