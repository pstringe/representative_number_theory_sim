#include "foundation.h"

void    f_putchar_fd(char c, int fd) {
    write(fd, &c, 1);
}