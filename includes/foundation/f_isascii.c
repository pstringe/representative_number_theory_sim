int     f_isascii(int c) {
    int is_ascii = (c >= 0 && c <= 127);
    return (is_ascii ? 1 : 0);
}