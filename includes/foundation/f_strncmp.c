#include "foundation.h"

int     f_strncmp(const char *s1, const char *s2, size_t n) {
    size_t      i;
    int         sum1;
    int         sum2;

    sum1 = 0;
    sum2 = 0;

    i = 0;
    while (s1[i] != '\0' && i < n) {
        sum1 += (int)s1[i];
        ++i;
    }
    i = 0;
    while (s2[i] != '\0' && i < n) {
        sum2 += (int)s2[i];
        ++i;
    }
    return (sum1 - sum2);
}