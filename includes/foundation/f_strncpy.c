#include "foundation.h"

char    *f_strncpy(char *dst, const char *src, size_t len) {
    int  n;
    int  i;

    n = f_strlen((char *)src);
    i = 0;
    while (i < (int)len && i < n) {
        dst[i] = src[i];
        i++;
    }
    return (dst);
}