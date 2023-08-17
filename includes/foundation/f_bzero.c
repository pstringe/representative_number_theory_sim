#include "foundation.h"

char    *f_bzero(void *s, size_t n) {
    return (f_memset(s, 0, n));
}