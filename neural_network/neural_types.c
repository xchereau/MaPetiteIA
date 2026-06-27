#include "neural_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef RAND_MAX
#define RAND_MAX 32767
#endif


float random_float(void) {
    static int seeded = 0;

    if (!seeded) {
        srand((unsigned int)time(NULL));
        seeded = 1;
    }

    int random_int = rand();

    // Convertit en float entre 0.0 et 1.0
    return (float)random_int / (float)RAND_MAX;
}

neural_network init_neural_network(const int nb_layer, const int *nb_neurals, const int *nb_enters) {
    
    //network innitialisation

    neural_network network;

    network.nb_layers = nb_layer;
    network.nb_neurals = malloc(nb_layer* sizeof(int));
    network.nb_enters = malloc(nb_layer* sizeof(int));  
    for (int i = 0; i < nb_layer; i++){
        network.nb_neurals[i] = nb_neurals[i];
        network.nb_enters[i]  = nb_enters[i];
    }

    //layers innitialisation
    network.layers = malloc(nb_layer *sizeof(layer));

    for (int id_layer = 0; id_layer < nb_layer ; id_layer++){
        network.layers[id_layer].nb_neurals = network.nb_neurals[id_layer];
        network.layers[id_layer].nb_enter = network.nb_enters[id_layer];

        //neural innitialisation
        network.layers[id_layer].neurals = malloc (network.layers[id_layer].nb_neurals * sizeof(neural));

        for (int id_neural = 0; id_neural < network.layers[id_layer].nb_neurals ; id_neural++){
            network.layers[id_layer].neurals[id_neural].nb_enter = network.layers[id_layer].nb_enter;
            network.layers[id_layer].neurals[id_neural].bias = random_float();

            network.layers[id_layer].neurals[id_neural].weight = malloc (network.layers[id_layer].neurals[id_neural].nb_enter* sizeof(float));

            for (int id_weight = 0; id_weight< network.layers[id_layer].neurals[id_neural].nb_enter; id_weight ++){
                network.layers[id_layer].neurals[id_neural].weight[id_weight] = random_float();
            }
        }
    }
    
    return network;
}

void free_network(neural_network net) {
    for (int l = 0; l < net.nb_layers; l++) {
        for (int n = 0; n < net.layers[l].nb_neurals; n++) {
            free(net.layers[l].neurals[n].weight);
        }
        free(net.layers[l].neurals);
    }
    free(net.layers);
    free(net.nb_neurals);
    free(net.nb_enters);
}