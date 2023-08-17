#include "foundation.h"

char    *f_strnew(int l) {
    char *s;

    s = (char*)f_memalloc(l + 1);
    f_bzero(s, l);
    return(s);
}
