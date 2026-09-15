#include "lists.h"

/**
 * get_nodeint_at_index - returns the node at a given index
 * @head: pointer to the head of the list
 * @index: index of the node, starting at 0
 *
 * Return: pointer to the node, or NULL if the node does not exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count = 0;

	while (head != NULL)
	{
		if (count == index)
			return (head);

		count++;
		head = head->next;
	}

	return (NULL);
}
