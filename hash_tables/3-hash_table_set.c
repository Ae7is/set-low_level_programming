#include "hash_tables.h"

/**
 * find_node - looks for a key in a linked list
 * @node: first node of the list
 * @key: the key to find
 * Return: the node holding the key, or NULL
 */
static hash_node_t *find_node(hash_node_t *node, const char *key)
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
 * hash_table_set - adds or updates an element in a hash table
 * @ht: the hash table
 * @key: the key, cannot be an empty string
 * @value: the value, duplicated by this function
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *node;
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
	node = malloc(sizeof(hash_node_t));
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
	return (1);
}
