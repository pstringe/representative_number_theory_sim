---
creation date:		2023-06-17 19:07
modification date:	2023-06-17 19:07
title: 				f_lstforeach
tags:
---
## Function: `f_lstforeach`

`void f_lstforeach(t_list *lst, void (*f)(), void **aux, int len);`

**Description:**

This function applies the function `f` to each node of the linked list `lst`, using additional data from the auxiliary array `aux` of length `len`.

**Parameters:**

- `lst`: Pointer to the linked list.
- `f`: Pointer to the function to be applied to each node.
- `aux`: Pointer to the auxiliary array.
- `len`: Length of the auxiliary array.

**Returns:**

None.