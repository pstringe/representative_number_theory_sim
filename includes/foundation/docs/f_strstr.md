---
creation date:		2023-06-17 18:18
modification date:	2023-06-17 18:18
title: 				f_strstr
tags:
---
## Function: `f_strstr`

`char *f_strstr(const char *big, const char *little);`

**Description:**

This function searches for the first occurrence of the string `little` in the string `big`.

**Parameters:**

- `big`: Pointer to the string to be searched.
- `little`: Pointer to the substring to search for.

**Returns:**

- Pointer to the first occurrence of `little` in `big`.
- `NULL` if `little` is not found.