---
creation date:		2023-06-17 18:32
modification date:	2023-06-17 18:32
title: 				f_strncmp
tags: metasyning
---

## Function: `f_strncmp`

`int f_strncmp(const char *s1, const char *s2, size_t n);`

**Description:**

This function compares at most `n` characters of the strings `s1` and `s2`.

**Parameters:**

- `s1`: Pointer to the first string.
- `s2`: Pointer to the second string.
- `n`: Maximum number of characters to compare.

**Returns:**

- `0` if the strings are equal.
- A negative value if `s1` is less than `s2`.
- A positive value if `s1` is greater than `s2`.