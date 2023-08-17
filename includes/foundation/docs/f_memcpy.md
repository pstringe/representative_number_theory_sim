---
creation date:		2023-06-17 18:36
modification date:	2023-06-17 18:36
title: 				f_memcpy
tags:
---
## Function: `f_memcpy`

`void *f_memcpy(void *dst, const void *src, size_t n);`

**Description:**

This function copies `n` bytes from the memory area pointed to by `src` to the memory area pointed to by `dst`. The memory areas must not overlap.

**Parameters:**

- `dst`: Pointer to the destination memory area.
- `src`: Pointer to the source memory area.
- `n`: Number of bytes to copy.

**Returns:**

Pointer to the destination memory area (`dst`).

**Note:**

- The behavior is undefined if `dst` or `src` is a null pointer.
- The behavior is undefined if the memory areas pointed to by `dst` and `src` overlap.

**Example:**

`char src[] = "Hello"; char dst[10]; f_memcpy(dst, src, 6); printf("%s", dst);  // Output: "Hello"`

In the example above, the string "Hello" is copied from `src` to `dst`, resulting in `dst` containing the same string "Hello".