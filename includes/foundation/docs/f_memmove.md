---
creation date:		2023-06-17 17:56
modification date:	2023-06-17 17:56
title: 				f_memmove
tags:
---
## Function: `f_memmove`

`void *f_memmove(void *dst, const void *src, size_t len);`

**Description:**

This function copies `len` bytes from `src` to `dst`. The memory areas may overlap.

**Parameters:**

- `dst`: Pointer to the destination memory.
- `src`: Pointer to the source memory.
- `len`: Number of bytes to copy.

**Returns:**

Pointer to the destination memory (`dst`).