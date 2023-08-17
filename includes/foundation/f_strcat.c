#include "foundation.h"

char    *f_strcat(char* s1, const char* s2 ) {
    int     n;
    int     m;
    int     i;

    n = f_strlen(s1);
    m = f_strlen((char *)s2);
    i = n;
    while (i < n + m) {
        s1[i] = s2[i - n];
        i++;
    }
    return (s1);
}