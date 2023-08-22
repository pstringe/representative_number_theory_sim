#include "foundation.h"
#include <stdio.h>

int     calc_weight(char *num) {
    int base;
    int i;

    i = f_strlen(num);
    base  = 1;
    while (--i) {
        base *= 10;
    } 
    return (base);
}

/*
char    *prepend(char *src, char *dst, size_t len) {
    int     i;

    dst[0] = 'm';
    dst[1] = '(';
    dst[len - 1] = ')';

    i = 2;
    while (i < len) {
        dst[i] = src;
    }
    return (dst);
}
*/



int     parse_num(char *num) {
    int     n;
    int     i;
    int     base;
    int     digit;

    base = calc_weight(num);
    i = 0;
    n = 0;
    while (base && *(num + i)) {
        digit = (int)(num[i] - 48);
        n += base * digit;
        base /= 10;
        i++;
    }
    return (n);
}

char    *succeed(char *src) {
    int     i;
    int     len;
    char    *dst;

    len = f_strlen(src);
    dst = f_strnew(len + 3);
    dst[0] = 'm';
    dst[1] = '(';
    dst[len + 2] = ')';
    i = 1;
    while (++i < len + 2) {
        dst[i] = *(src + i - 2);
    }
    return (dst);
}

int     main (int argc, char **argv) {
    char    *num;

    if (argc < 2){
        return 0;
    }
    
    num = argv[2];
    f_putstr(succeed(num));
    f_putchar('\n');
    return (0);
}
