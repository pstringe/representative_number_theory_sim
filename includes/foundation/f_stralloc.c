#include "foundation.h"

char    *f_stralloc(char *src) {
    char    *new;
    int     n;

    n = f_strlen(src);
    new = (char*)f_memalloc(sizeof(char) * n);
    f_strncpy(new , src, n);
    return (new);
}