#include "foundation.h"

/*
**    To extract the last digit from n, we can mod by 10
**    To modify n such that the last digit is removed, we can divide by 10
*/

char    f_dtoc(int n) {
    if (n > 9 || n < 0) {
        return (0);
    }
    return ((n + 48));
}