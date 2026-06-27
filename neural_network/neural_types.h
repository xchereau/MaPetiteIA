

typedef struct {
    // neural parameters
    float bias;
    int nb_enter;
    float * weight;
} neural;

typedef struct {
    // layer parameters
    neural *neurals;
    int nb_neurals;
    // neural_parameters
    int nb_enter;
} layer;

typedef struct {
    // neural_network parameters
    layer *layers;
    int nb_layers;
    // layer parameters
    int *nb_neurals;
    // neural parameters
    int *nb_enters;
} neural_network;

neural_network init_neural_network (const int nb_layer,const int *nb_neurals,const int *nb_enters);
void free_network(neural_network net) 