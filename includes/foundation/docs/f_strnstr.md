---
creation date:		2023-06-17 18:20
modification date:	2023-06-17 18:20
title: 				f_strnstr
tags:
---
## Function: `f_strnstr`

`char *f_strnstr(const char *big, const char *sm, size_t len);`

**Description:**

This function searches for the first occurrence of the string `sm` in the string `big` within the first `len` characters.

**Parameters:**

- `big`: Pointer to the string to be searched.
- `sm`: Pointer to the substring to search for.
- `len`: Maximum number of characters to search.

**Returns:**

- Pointer to the first occurrence of `sm` in `big` within the first `len` characters.
- `NULL` if `sm` is not found.