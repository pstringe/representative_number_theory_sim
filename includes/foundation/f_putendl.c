#include "foundation.h"

int     f_putendl(char *s) {
    int bytes_written = 0;
    bytes_written = f_putstr(s);
    f_putchar('\n');
    return (bytes_written + 1);
}