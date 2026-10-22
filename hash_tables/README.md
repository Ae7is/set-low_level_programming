# hash_tables

A C project that implements a hash table with chaining for collision handling,
the djb2 hash function, and a sorted hash table that keeps its keys in ASCII
order.

## Requirements

- Compiled on Ubuntu with `gcc` using
  `-Wall -pedantic -Werror -Wextra -std=gnu89`
- Code follows the Betty style
- No global variables, and no more than 5 functions per file (except
  `100-sorted_hash_table.c`)
- All prototypes are in `hash_tables.h`, which is include guarded

## Data Structures

| Type | Description |
|---|---|
| `hash_node_t` | Node of a hash table list: `key`, `value`, `next` |
| `hash_table_t` | Hash table: `size` and an `array` of node lists |
| `shash_node_t` | Sorted hash table node, adds `sprev` and `snext` for the sorted list |
| `shash_table_t` | Sorted hash table: `size`, `array`, `shead` and `stail` |

## Files

| File | Function | Description |
|---|---|---|
| `hash_tables.h` | | Structures and function prototypes |
| `0-hash_table_create.c` | `hash_table_create` | Creates a hash table, or returns `NULL` on failure |
| `1-djb2.c` | `hash_djb2` | The djb2 hash function |
| `2-key_index.c` | `key_index` | Gives the array index for a key, using djb2 |
| `3-hash_table_set.c` | `hash_table_set` | Adds or updates a key/value pair (the value is duplicated). A new node goes at the beginning of its list on collision |
| `4-hash_table_get.c` | `hash_table_get` | Returns the value of a key, or `NULL` if not found |
| `5-hash_table_print.c` | `hash_table_print` | Prints the table in array order, then list order |
| `6-hash_table_delete.c` | `hash_table_delete` | Frees the whole table |
| `100-sorted_hash_table.c` | `shash_table_create`, `shash_table_set`, `shash_table_get`, `shash_table_print`, `shash_table_print_rev`, `shash_table_delete` | The same operations on a sorted hash table. Pairs are kept in a linked list sorted by key (ASCII order), so they can be printed forward or in reverse |

## Prototypes

```c
hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
char *hash_table_get(const hash_table_t *ht, const char *key);
void hash_table_print(const hash_table_t *ht);
void hash_table_delete(hash_table_t *ht);

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);
```

## Behavior Notes

- Keys cannot be empty strings. A `NULL` key or value makes `set` return `0`.
- Both the key and the value are copied with `strdup`, so changing or freeing
  the caller's strings later does not affect the table.
- Setting an existing key replaces its value (no duplicate keys).
- The print functions print nothing if the table is `NULL`.

## Compilation and Example

```bash
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 main.c 0-hash_table_create.c \
    1-djb2.c 2-key_index.c 3-hash_table_set.c 4-hash_table_get.c \
    5-hash_table_print.c 6-hash_table_delete.c -o hash
```

```c
hash_table_t *ht = hash_table_create(1024);

hash_table_set(ht, "c", "fun");
hash_table_set(ht, "python", "awesome");
printf("%s\n", hash_table_get(ht, "python"));   /* awesome */
hash_table_print(ht);
hash_table_delete(ht);
```

For the sorted version, compile `100-sorted_hash_table.c` with `1-djb2.c` and
`2-key_index.c`.

## Memory

All allocations are freed by `hash_table_delete` and `shash_table_delete`.
Checked with `valgrind`.

## Author

[Ejike Gabriel Wokama]
