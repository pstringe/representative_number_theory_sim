#include "foundation.h"

char    **f_array_append(char **array, char *item) {
    int n;

    n = f_array_len(array);
    f_array_resize(&array, 1);
    array[n] = f_stralloc(item);
    return (array);
}
