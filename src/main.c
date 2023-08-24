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

char    *succeed(char *src, char *notation) {
    int     i;
    int     len;
    char    *dst;

    len = f_strlen(src);
    dst = f_strnew(len + 3);
    
    dst[0] = f_strcmp(notation, "infix") == 0 ? 'm' : '(';
    dst[1] = f_strcmp(notation, "infix") == 0 ? '(' : 'm';
    dst[len + 2] = ')';

    i = 1;
    while (++i < len + 2) {
        dst[i] = *(src + i - 2);
    }
    return (dst);
}

char    *f_strdup(char *s){
    int    len;
    int     i;
    char    *dup;

    len = f_strlen(s);
    dup = f_strnew(len);
    i = 0;
    while (i < len) {
        dup[i] = s[i];
        i++;
    }
    return (dup);
}

//write a memdel function


char    *generation(char *prima, int sucessions, char *notation) {
    int     i;
    char    *tmp;
    char    *meta;
    
    meta = f_strdup(prima);
    i = 0;
    while (i++ < sucessions) {
        tmp = f_strdup(meta);
        f_bzero(meta, f_strlen(meta));
        meta = succeed(tmp, notation);
    }
    return(meta);
}

int     main (int argc, char **argv) {
    char    *meta;
    char    *prima;
    char    *sucessions;
    char    *notation;

    if (argc < 2){
        return 0;
    }
    
    prima = argv[2];
    sucessions = argv[1];
    notation = argv[3];

    meta = generation(prima, parse_num(sucessions), notation);
    f_putendl(meta);
    return (0);
}