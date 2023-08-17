#include "foundation.h"

void    *f_memset(void *s, int c, size_t n) {
    char *ss;

    ss = (char *)s;
    while (n--){
        ss[n] = (char)c;
    }
    return ss;
}