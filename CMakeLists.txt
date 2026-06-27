cmake_minimum_required(VERSION 3.10)  # Version minimale de CMake requise

set(CMAKE_C_COMPILER "gcc")
add_compile_options(-Wall )
project(MAPETITEIA C)   


add_executable(
    MAPETITEIA
    main.c
    get_mnist_data/get_mnist_vector.c
    neural_network/neural_types.c
    neural_network/compute_neural_network.c
)

target_include_directories(
    MAPETITEIA PRIVATE include 
    get_mnist_data
    neural_network
)

