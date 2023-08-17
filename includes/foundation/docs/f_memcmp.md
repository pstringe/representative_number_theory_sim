---
creation date:		2023-06-17 18:31
modification date:	2023-06-17 18:31
title: 				f_memcmp
tags:
---
## Function: `f_memcmp`

`int f_memcmp(const void *s1, const void *s2, size_t n);`

**Description:**

This function compares the first `n` bytes of the memory areas `s1` and `s2`.

**Parameters:**

- `s1`: Pointer to the first memory area.
- `s2`: Pointer to the second memory area.
- `n`: Number of bytes to compare.

**Returns:**

- `0` if the memory areas are equal.
- A negative value if the first differing byte in `s1` is less than the corresponding byte in `s2`.
- A positive value if the first differing byte in `s1` is greater than the corresponding byte in `s2`.