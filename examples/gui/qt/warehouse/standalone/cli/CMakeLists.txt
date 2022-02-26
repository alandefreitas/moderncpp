add_executable(warehouse_cli
        main.cpp
        application.h
        application.cpp
        )
target_link_libraries(warehouse_cli PRIVATE warehouse_lib)