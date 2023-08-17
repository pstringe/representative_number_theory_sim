/*
** our high level approach is to read bytes into a buffer untile we reach a new line 
** or end of file. 
** Upon reaching that char, we allocate an new array and copy the bytes over.
** We then assingn that array to our line pointer, update the filedes pointer by 
** passing the return value of read to lseek, and clear the buffer.
*/
#include "foundation.h"

int f_gnl(const int fd, char **line) {
    // allocate static array to store bytes
    char buffer[4096];
    char *new;
    // declare var to keep track of bytes read
    size_t bytes;

    // instanciate loop to itterate while read byte is not '\n' or EOF
    bytes = read(fd, buffer, 1);
    while (bytes >= 0 && buffer[bytes - 1] != '\n' && buffer[bytes - 1] != EOF) {
        //copy each byte to buffer
        bytes += read(fd, buffer, 1);
    }
    new = f_strnew(f_strlen(buffer));
    f_strncpy(new, buffer, bytes);
    *line = new;
    return (bytes);
}