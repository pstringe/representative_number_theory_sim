#include "foundation.h"

char    **g(const char *str, char delim, char *cur, char **res, int len) {
    int     bytes;
    char    *next_delim;

    if (!str) {
        return (res);
    } else if (*str != delim) {
        next_delim = f_strchr(str, delim);
        bytes = next_delim != NULL ? next_delim - str : len - (int)str;
        return g(str + bytes, delim, f_strncat(cur, str, bytes), res, len);
    }
    f_array_append(res, cur);
    return g(str + 1, delim, f_bzero(cur, f_strlen(cur)), res, len);
}

char    **f_strsplit(char const *s, char c) {
    int     SIZE = 20;  
    char    *tmp;
    int     len;
    char    **res;

    len = f_strcount((char*)s, c);
    //allocate extra pointer since there will be one more word than there are delimiters
    //allocate extra pointer for terminator
    res = (char **)f_memalloc(sizeof(char *) * len + 1 + 1);
    tmp = f_strnew(SIZE);

    return (g(s, c, tmp, res, f_strlen((char*)s)));
}