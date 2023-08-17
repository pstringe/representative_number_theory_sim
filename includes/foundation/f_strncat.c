#include "foundation.h"

char    *f_strncat(char *s1, const char *s2, size_t n) {
    int i;
    int l;
    int m;

    l = f_strlen((char *)s1);
    m = f_strlen((char *)s2);
    i = 0;
    while (i + l < (int)n && i + l < m) {
        s1[i + l] = s2[i];
        i ++;
    }
    return (s1);
}