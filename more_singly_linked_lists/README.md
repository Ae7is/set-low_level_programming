This directory contains coding projects on More singly linked list Part One.

Frontier Institute of Technology.
SE201.
Wokama Ejike Gabriel.

# more_singly_linked_lists

C functions for singly linked lists (`listint_t`): sum, insert, delete,
reverse, and safe print and free for lists that contain a loop.

## Rules

- Compiled with `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`, Betty style
- No global variables, at most 5 functions per file
- Only `malloc`, `free` and `exit` from the standard library, plus `_putchar`
- All prototypes are in `lists.h`

## Files

| File | Function |
|---|---|
| `8-sum_listint.c` | `sum_listint`: sum of all node values |
| `9-insert_nodeint.c` | `insert_nodeint_at_index`: insert a node at an index |
| `10-delete_nodeint.c` | `delete_nodeint_at_index`: delete the node at an index |
| `100-reverse_listint.c` | `reverse_listint`: reverse a list in place |
| `101-print_listint_safe.c` | `print_listint_safe`: print a list, even with a loop |
| `102-free_listint_safe.c` | `free_listint_safe`: free a list, even with a loop |
| `103-find_loop.c` | `find_listint_loop`: find where a loop starts |
