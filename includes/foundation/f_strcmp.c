#include "foundation.h"

int     f_strcmp(const char *s1, const char *s2) {
    int     i;
    int     n;
    int     m;

    n = f_strlen((char *)s1);
    m = f_strlen((char *)s2);
    i = 0;
    while (i < n && i < m) {
        if (!(s1[i] == s2[i])) return (-1);
        i++;
    }
    return (0);
}