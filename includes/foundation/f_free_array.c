char    **f_free_array(char** arr) {
    int i;
    int j;

    i = 0;
    while (arr[i] != NULL) {
        j = f_strlen(*arr);
        f_bzero(arr[i], f_strlen(*(arr + i)));
        free(arr[i]);
        i++;
    }
    return arr;
}
