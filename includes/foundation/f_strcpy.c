char    *f_strcpy(char *dst, const char *src) {
    int     i;

    //n = f_strlen((char *)src);
    i = 0;
    while (dst[i]) {
        dst[i] = src[i];
        i++;
    }
    return (dst);
}