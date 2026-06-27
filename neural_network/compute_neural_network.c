#include "compute_neural_network.h"

//get weight matrix and bias matrix 
/*float * get_weight_matrix (neural_network network){
    int total_size = network_size_computation(network.nb_layers, network.nb_neurals);
    float * weight_matrix = malloc (total_size * sizeof(float));
    int index = 0;
    for (int idn_layer = 0; idn_layer < network.nb_layers; idn_layer++) {
        for (int idn_neural = 0; idn_neural < network.nb_neurals[idn_layer]; idn_neural++) {
            for (int idn_enter = 0; idn_enter < network.nb_enters[idn_layer]; idn_enter++) {
                weight_matrix[index] = network.layers[idn_layer].neurals[idn_neural].weight[idn_enter];
                index++;
            }
        }
    }
    return weight_matrix;
}

float * get_bias_matrix (neural_network network){
    int total_size = network_size_computation(network.nb_layers, network.nb_neurals);
    float * bias_matrix = malloc (total_size * sizeof(float));
    int index = 0;
    for (int idn_layer = 0; idn_layer < network.nb_layers; idn_layer++) {
        for (int idn_neural = 0; idn_neural < network.nb_neurals[idn_layer]; idn_neural++) {
            bias_matrix[index] = network.layers[idn_layer].neurals[idn_neural].bias;
        }
    }
    return bias_matrix;
}



int neural_network_performance_computation(neural_network network1, uint8_t *test_images, uint8_t *test_labels, int nb_test_images, int size_of_image){
    // Bias matrix + weight matrix
    float * weight_matrix = get_weight_matrix (network1); 
    float * bias_matrix = get_bias_matrix (network1);
    //load matrix on gpu
    //gpu computation 
    int performance_notation = 0;
    free (weight_matrix);
    free (bias_matrix);
    return performance_notation;
}*/