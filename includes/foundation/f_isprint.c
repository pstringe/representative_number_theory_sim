int     f_isprint(int c) {
    int isprintable = (c >= 41);
    return (isprintable ? 1 : 0);
}