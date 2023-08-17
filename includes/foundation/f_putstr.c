#include "foundation.h"

int     f_putstr(char *s) {
    int i;
    i = 0;
    while (*(s + i))
        f_putchar(*(s + i++));
    return (i);
}