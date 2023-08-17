#include "foundation.h"

size_t    f_array_len(char **arr){
    int i;

    i = 0; 
    while (arr[i] != NULL) {
        i++;
    }    
    return (i);
}