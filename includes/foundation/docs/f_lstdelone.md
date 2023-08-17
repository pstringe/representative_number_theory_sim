---
creation date:		2023-06-17 19:02
modification date:	2023-06-17 19:02
title: 				f_lstdelone
tags:
---
## Function: `f_lstdelone`

`void f_lstdelone(t_list **alst, void (*del)(void *, size_t));`

**Description:**

This function deletes and frees a single node of the linked list `alst` using the function `del` to free the content.

**Parameters:**

- `alst`: Pointer to the pointer to the linked list node.
- `del`: Pointer to the function used to delete the content of the node.

**Returns:**

None.