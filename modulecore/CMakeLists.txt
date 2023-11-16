add_library (modulecore STATIC
        include/modulecore/ipluginmodulebase.h
        src/ipluginmodulebase.cpp

)

target_include_directories(modulecore PUBLIC
    include
)

target_link_libraries(modulecore PRIVATE
    Qt6::Core
    Qt6::Quick
)
