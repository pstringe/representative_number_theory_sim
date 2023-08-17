---
creation date:		2023-06-17 19:02
modification date:	2023-06-17 19:02
title: 				f_lstdel
tags:
---
## Function: `f_lstdel`

cCopy code

`void f_lstdel(t_list **alst, void (*del)(void *, size_t));`

**Description:**

This function deletes and frees each node of the linked list `alst` using the function `del` to free the content.

**Parameters:**

- `alst`: Pointer to the pointer to the linked list.
- `del`: Pointer to the function used to delete the content of each node.

**Returns:**

None.