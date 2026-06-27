#include <stdio.h>
#include <stdint.h>

#include "get_mnist_vector.h"
//#include "neural_types.h"
#include "compute_neural_network.h"
#define NB_TEST_IMAGES

int main (void){
    //#####################################
    // DEFINE MATRIX WHICH CONTAINING DATA
    //#####################################
    const char *path_train_image = "X:\\MaPetiteIA\\get_mnist_data\\train_images.bin";
    const char *path_train_label = "X:\\MaPetiteIA\\get_mnist_data\\train_labels.bin";
    const char *path_test_image  = "X:\\MaPetiteIA\\get_mnist_data\\test_images.bin";
    const char *path_test_label  = "X:\\MaPetiteIA\\get_mnist_data\\test_labels.bin";
    const int size_of_image   = 28*28;
    const int nb_test_images  = 10000;
    const int nb_train_images = 60000;

    uint8_t *train_images = malloc (nb_train_images * size_of_image *sizeof(uint8_t));
    uint8_t *train_labels = malloc (nb_train_images * sizeof(uint8_t));
    uint8_t *test_images  = malloc (nb_test_images  * size_of_image *sizeof(uint8_t));
    uint8_t *test_labels  = malloc (nb_test_images  * sizeof(uint8_t));
    
    get_signal (train_images,(int)(nb_train_images*size_of_image) ,path_train_image);
    get_signal (train_labels,(int)(nb_train_images)               ,path_train_label);
    get_signal (test_images ,(int)(nb_test_images * size_of_image),path_test_image );
    get_signal (test_labels ,(int)(nb_test_images)                ,path_test_label );
    
    //uint8_t labels =14000;
    //print_images(train_images,train_labels,labels);

    //#####################################
    // CREATE NEURAL NETWORK
    //#####################################

    const int nb_layer = 3;
    const int *nb_neurals [] = {10,10,10};
    const int *nb_enters [] = {28*28,10,10};

    neural_network network1 = init_neural_network( nb_layer, nb_neurals, nb_enters);

    //#####################################
    // COMPUTE_FUNCTION
    //#####################################

    //int initialperformance = neural_network_performance_computation(network1, test_images, test_labels, nb_test_images, size_of_image);
    //printf ("Initial performance of the neural network: %d\n", initialperformance);

    //#####################################
    // CLOSE THE PROGRAMME
    //#####################################

    printf("hello world!\n\r");

    free(train_images);
    free(train_labels);
    free(test_images); 
    free(test_labels);

    free_network(network1);

    //free(network1);
    return 0;
} 