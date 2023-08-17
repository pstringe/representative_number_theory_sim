int     f_iswhitespace(char c) {
    char*   whitespace_chars;
    int     i;

    whitespace_chars = " \t\r\n\f";
    i = 0;
    while (whitespace_chars[i]) {
        if (c == whitespace_chars[i++]) {
            return (1);
        }
    }
    
    return (0);
}