#include "foundation.h"

void    *f_memalloc(size_t size) {
    void    *memory;
    memory = (void*)malloc(size);
    f_memset(memory, 0, size);
    return (memory);
}