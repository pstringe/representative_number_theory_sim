#include "foundation.h"

char    **f_array_resize(char ***array, size_t incr) {
    int     n;
    int     m;
    int     i;
    char    **new;

    n = f_array_len(*array);
    new = (char**)f_memalloc((n + incr) * sizeof(char *));
    i = 0;
    while (i < n) {
        m = f_strlen(*array[i]);
        f_strncpy(new[i], *array[i], m);
        i++;
    }
    free(*array);
    array = &new;
    return (*array);
}