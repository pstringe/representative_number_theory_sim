---
creation date:		2023-06-17 18:54
modification date:	2023-06-17 18:54
title: 				f_memchr
tags:
---
## Function: `f_memchr`

`void *f_memchr(const void *s, int c, size_t n);`

**Description:**

This function searches for the first occurrence of the character `c` in the first `n` bytes of the memory pointed to by `s`.

**Parameters:**

- `s`: Pointer to the memory to be searched.
- `c`: Character to search for.
- `n`: Number of bytes to search.

**Returns:**

- Pointer to the first occurrence of `c` in the memory.
- `NULL` if `c` is not found.