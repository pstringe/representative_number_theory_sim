#include "foundation.h"

char    *f_strstr(const char *big, const char *little) {
    int n;
    int m;
    int i;
    int j;

    n = f_strlen((char *)big);
    m = f_strlen((char *)little);

    i = 0;
    while (*(big + i) != '\0') {
        j = 0;
        while (big[i + j] == little[j]) {
            j++;
        }
        if (j == m) {
            return ((char *)(big + i));
        }
        i++;
    }
    return ((char *)(big + (i - m)));
}