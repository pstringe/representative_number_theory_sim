int     f_isalpha(char c) {
    int is_lower;
    int is_upper;

    is_lower = (c >= 97 && c <= 122);
    is_upper = (c >= 65 && c <= 90);
    return ((is_lower || is_upper) ? 1 : 0);
}