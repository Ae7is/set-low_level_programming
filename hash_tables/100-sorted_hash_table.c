#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the array
 * Return: pointer to the new table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	if (size == 0)
		return (NULL);

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;
	ht->size = size;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * find_node - looks for a key in a linked list
 * @node: first node of the list
 * @key: the key to find
 * Return: the node holding the key, or NULL
 */
static shash_node_t *find_node(shash_node_t *node, const char *key)
{
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * insert_sorted - inserts a node in the sorted list, ordered by key
 * @ht: the sorted hash table
 * @node: the node to insert
 */
static void insert_sorted(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *cur;

	cur = ht->shead;
	while (cur != NULL && strcmp(cur->key, node->key) < 0)
		cur = cur->snext;

	if (cur == NULL)
	{
		node->sprev = ht->stail;
		node->snext = NULL;
		if (ht->stail != NULL)
			ht->stail->snext = node;
		else
			ht->shead = node;
		ht->stail = node;
		return;
	}

	node->snext = cur;
	node->sprev = cur->sprev;
	if (cur->sprev != NULL)
		cur->sprev->snext = node;
	else
		ht->shead = node;
	cur->sprev = node;
}

/**
 * shash_table_set - adds or updates an element in a sorted hash table
 * @ht: the sorted hash table
 * @key: the key, cannot be an empty string
 * @value: the value, duplicated by this function
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *node;
	char *new_value;

	if (ht == NULL || key == NULL || key[0] == '\0' || value == NULL)
		return (0);
	new_value = strdup(value);
	if (new_value == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	node = find_node(ht->array[index], key);
	if (node != NULL)
	{
		free(node->value);
		node->value = new_value;
		return (1);
	}
	node = malloc(sizeof(shash_node_t));
	if (node == NULL)
	{
		free(new_value);
		return (0);
	}
	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(new_value);
		free(node);
		return (0);
	}
	node->value = new_value;
	node->next = ht->array[index];
	ht->array[index] = node;
	insert_sorted(ht, node);
	return (1);
}

/**
 * shash_table_get - retrieves the value associated with a key
 * @ht: the sorted hash table
 * @key: the key to look for
 * Return: the value, or NULL if the key cannot be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;

	if (ht == NULL || key == NULL || key[0] == '\0')
		return (NULL);

	node = find_node(ht->array[key_index((const unsigned char *)key,
					     ht->size)], key);
	if (node == NULL)
		return (NULL);

	return (node->value);
}

/**
 * shash_table_print - prints a sorted hash table, in key order
 * @ht: the sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	printf("{");
	for (node = ht->shead; node != NULL; node = node->snext)
	{
		printf("'%s': '%s'", node->key, node->value);
		if (node->snext != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table, in reverse key order
 * @ht: the sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	printf("{");
	for (node = ht->stail; node != NULL; node = node->sprev)
	{
		printf("'%s': '%s'", node->key, node->value);
		if (node->sprev != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: the sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node;
	shash_node_t *next;

	if (ht == NULL)
		return;

	node = ht->shead;
	while (node != NULL)
	{
		next = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = next;
	}
	free(ht->array);
	free(ht);
}
