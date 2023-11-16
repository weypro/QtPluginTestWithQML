add_library (appcore OBJECT
        include/appcore/myappdemo.h
        src/myappdemo.cpp

)

target_include_directories(appcore PUBLIC
    include
    ../include

)

target_link_libraries(appcore PRIVATE
    Qt6::Core
    Qt6::Quick
)
