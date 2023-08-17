/*
** 
*/

int     f_strcount(char *s, char c) {
    int     i;
    int     count;
    
    count = 0;
    i = 0;
    while (s[i]) {
        if (s[i] == c) {
            count++;
        }
        i++;
    }
    return (count);
}
