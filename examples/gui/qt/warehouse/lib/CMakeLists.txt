add_library(warehouse_lib
        warehouse.cpp
        warehouse.h
        product.cpp
        product.h
        )
target_include_directories(warehouse_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})