#include <stdint.h>
#include "get_mnist_vector.h"



int get_signal(uint8_t *table_adrress,int max_size,const char *path_file)
{
    FILE *f;
    printf("Open the file : %s\n\r", path_file);
    unsigned char octet;
    f = fopen (path_file,"rb");
    if (f==NULL)
    {
        //printf ("Couldn't open the file %s\n\r",path_file);
        printf("error");
        return 1;
    }

    int counter = 0;
    while (fread(&octet, sizeof(uint8_t), 1, f) == 1) {
        if (counter >= max_size){
            perror ("Couldn't put more data inside the table");
            return 1;
        }
        *(table_adrress+counter*sizeof(uint8_t))=octet;
        counter ++;
    }
    printf ("%d data image have been capture\n\r",counter);
    fclose(f);
    return 0;
}

int print_images(uint8_t *images ,uint8_t *labels ,uint8_t label_number){
    printf("Labels %d: %d\n\r",label_number,*(labels+label_number*sizeof(uint8_t)));
    uint8_t *image = (images+label_number*sizeof(uint8_t));
    for (uint8_t line = 0 ; line <28 ;line++){
        for (uint8_t index = 0 ; index<28 ; index++){
            char pixel_value = (*(image+line*28+index)>127) ? '#' : ' '; 
            printf("%c",pixel_value); 
        }
        printf("\n\r");
    }
    return 0;
}