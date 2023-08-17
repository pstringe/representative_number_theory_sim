#include "foundation.h"

char    *f_memcpy(char *dst, const char *src, size_t n) {
    size_t  i;
    i = 0;

    while (dst[i] && src[i] && i < n) {
        dst[i] = src[i];
    }
    return (dst);
}