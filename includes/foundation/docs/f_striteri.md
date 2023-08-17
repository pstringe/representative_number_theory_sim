---
creation date:		2023-06-17 18:42
modification date:	2023-06-17 18:42
title: 				f_striteri
tags:
---
## Function: `f_striteri`

cCopy code

`void f_striteri(char *s, void (*f)(unsigned int, char *));`

**Description:**

This function applies the function `f` to each character of the string `s`, providing its index as the first argument.

**Parameters:**

- `s`: Pointer to the string to iterate over.
- `f`: Pointer to the function to be applied to each character.

**Returns:**

None.