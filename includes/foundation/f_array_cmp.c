#include "foundation.h"

/*
** cmp() return 0 if the inputs match and 1 if they don't match
*/

char    f_array_cmp(char **a1, char **a2, int (*cmp) (char*, char*)) {
    int i;
    int n;
    int m; 

    n = f_array_len(a1);
    m = f_array_len(a2);

    if (n != m) return 0;

    i = 0;
    while (i < n) {
        if (cmp(a1[i], a2[i])){
            return (1);    
        }
        i++;
    }
    return (0);
}
