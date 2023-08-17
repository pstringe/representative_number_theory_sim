---
creation date:		2023-06-17 18:16
modification date:	2023-06-17 18:16
title: 				f_strncpy
tags:
---
## Function: `f_strncpy`


`char *f_strncpy(char *dst, const char *src, size_t len);`

**Description:**

This function copies at most `len` characters from `src` to `dst`. If `src` is shorter than `len`, the remaining characters in `dst` are filled with null characters.

**Parameters:**

- `dst`: Pointer to the destination string.
- `src`: Pointer to the source string.
- `len`: Maximum number of characters to copy.

**Returns:**

Pointer to the modified destination string (`dst`).