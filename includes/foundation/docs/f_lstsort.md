---
creation date:		2023-06-17 19:07
modification date:	2023-06-17 19:07
title: 				f_lstsort
tags:
---
## Function: `f_lstsort`

cCopy code

`void f_lstsort(t_list *begin, int (*cmp)(void *, void *, void **, int), void **aux, int len);`

**Description:**

This function sorts a linked list `begin` using a custom comparison function `cmp`. It also takes an auxiliary array `aux` and its length `len` for additional data needed during the sorting process.

**Parameters:**

- `begin`: Pointer to the head of the linked list.
- `cmp`: Pointer to the comparison function.
- `aux`: Pointer to the auxiliary array.
- `len`: Length of the auxiliary array.

**Returns:**

None.