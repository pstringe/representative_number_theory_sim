---
creation date:		2023-06-17 19:04
modification date:	2023-06-17 19:04
title: 				f_lstmap
tags:
---
## Function: `f_lstmap`

cCopy code

`t_list *f_lstmap(t_list *lst, t_list *(*f)(t_list *elem));`

**Description:**

This function applies the function `f` to each node of the linked list `lst` and creates a new list with the results.

**Parameters:**

- `lst`: Pointer to the linked list.
- `f`: Pointer to the function to be applied to each node.

**Returns:**

Pointer to the newly created list.