add_executable(raw_arrays raw_arrays.cpp)

add_executable(arrays arrays.cpp)

add_executable(vectors vectors.cpp)

add_executable(strings strings.cpp)

add_executable(move move.cpp)

add_executable(struct struct.cpp)

#[aggregate_initialization CMakeLists.txt
add_executable(aggregate_initialization aggregate_initialization.cpp)
target_compile_features(aggregate_initialization PRIVATE cxx_std_20)
#]

#[structured_binding CMakeLists.txt
add_executable(structured_binding structured_binding.cpp)
target_compile_features(structured_binding PRIVATE cxx_std_17)
#]
