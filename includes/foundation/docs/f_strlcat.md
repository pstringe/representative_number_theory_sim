---
creation date:		2023-06-17 19:06
modification date:	2023-06-17 19:06
title: 				f_strlcat
tags:
---
## Function: `f_strlcat`

`int f_strlcat(char *dst, char const *src, size_t size);`

**Description:**

This function appends the string `src` to the end of `dst`, ensuring that the total length of the resulting string does not exceed `size`.

**Parameters:**

- `dst`: Pointer to the destination string.
- `src`: Pointer to the source string.
- `size`: Size of the destination string buffer.

**Returns:**

The total length of the resulting string.