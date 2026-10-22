#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table in array order, then list order
 * @ht: the hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node;
	int first;

	if (ht == NULL)
		return;

	printf("{");
	first = 1;
	for (i = 0; i < ht->size; i++)
	{
		for (node = ht->array[i]; node != NULL; node = node->next)
		{
			if (!first)
				printf(", ");
			printf("'%s': '%s'", node->key, node->value);
			first = 0;
		}
	}
	printf("}\n");
}
