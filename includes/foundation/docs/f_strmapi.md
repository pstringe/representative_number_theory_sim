---
creation date:		2023-06-17 17:57
modification date:	2023-06-17 17:57
title: 				f_strmapi
tags:
---
## Function: `f_strmapi`

`char *f_strmapi(char const *s, char (*f)(unsigned int, char));`

**Description:**

This function applies the function `f` to each character of the string `s`, providing its index as the first argument, and creates a new string with the results.

**Parameters:**

- `s`: Pointer to the string to be mapped.
- `f`: Pointer to the mapping function.

**Returns:**

Pointer to the newly allocated mapped string.