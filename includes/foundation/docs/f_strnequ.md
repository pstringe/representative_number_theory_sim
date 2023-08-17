---
creation date:		2023-06-17 18:48
modification date:	2023-06-17 18:48
title: 				f_strnequ
tags:
---
## Function: `f_strnequ`

`int f_strnequ(char const *s1, char const *s2, size_t n);`

**Description:**

This function compares at most `n` characters of the strings `s1` and `s2` for equality.

**Parameters:**

- `s1`: Pointer to the first string.
- `s2`: Pointer to the second string.
- `n`: Maximum number of characters to compare.

**Returns:**

- `1` if the strings are equal.
- `0` otherwise.