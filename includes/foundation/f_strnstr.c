#include "foundation.h"

char    *f_strnstr(const char *big, const char *sm, size_t len) {
    int     i;
    int     j;
    int     n;
    int     m;

    n = f_strlen((char *)big);
    m = f_strlen((char *)sm);
    i = 0;
    while (i < (int)len && i < n) {
        j = 0;
        while (big[i + j] == sm[j]) {
            j++;
        }
        if (j == m) {
            return ((char *)(big + i));
        }
        i++;
    }
    return (NULL);
}