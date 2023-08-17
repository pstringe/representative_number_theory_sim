int     f_isdigit(char c) {
    int is_num;
    
    is_num = (c >= 48 && c <= 57);
    return (is_num);
}