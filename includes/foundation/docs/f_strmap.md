---
creation date:		2023-06-17 18:44
modification date:	2023-06-17 18:44
title: 				f_strmap
tags:
---
## Function: `f_strmap`

`char *f_strmap(char const *s, char (*f)(char));`

**Description:**

This function applies the function `f` to each character of the string `s` and creates a new string with the results.

**Parameters:**

- `s`: Pointer to the string to be mapped.
- `f`: Pointer to the mapping function.

**Returns:**

Pointer to the newly allocated mapped string.

---