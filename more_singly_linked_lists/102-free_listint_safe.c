#include "lists.h"

/**
 * count_nodes - counts the distinct nodes of a list, even with a loop
 * @head: pointer to the first node
 * Return: the number of distinct nodes
 */
static size_t count_nodes(const listint_t *head)
{
	const listint_t *current;
	const listint_t *scan;
	size_t count;
	size_t i;

	count = 0;
	current = head;
	while (current != NULL)
	{
		count++;
		scan = head;
		for (i = 0; i < count && current->next != NULL; i++)
		{
			if (scan == current->next)
				return (count);
			scan = scan->next;
		}
		current = current->next;
	}

	return (count);
}

/**
 * free_listint_safe - frees a listint_t list, even if it has a loop
 * @h: pointer to the first node pointer
 * Return: the number of nodes freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *tmp;
	size_t count;
	size_t i;

	if (h == NULL || *h == NULL)
		return (0);

	count = count_nodes(*h);
	for (i = 0; i < count; i++)
	{
		tmp = (*h)->next;
		free(*h);
		*h = tmp;
	}
	*h = NULL;

	return (count);
}
