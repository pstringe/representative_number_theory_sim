#include "foundation.h"

size_t    f_array_len(void **arr){
    int i;

    i = 0; 
    while (arr[i] != NULL) {
        i++;
    }    
    return (i);
}