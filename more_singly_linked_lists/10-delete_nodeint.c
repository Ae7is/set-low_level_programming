#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at a given index
 * @head: pointer to the first node pointer
 * @index: index of the node to delete, starting at 0
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current;
	listint_t *tmp;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		tmp = *head;
		*head = tmp->next;
		free(tmp);
		return (1);
	}

	current = *head;
	for (i = 0; current->next != NULL && i < index - 1; i++)
		current = current->next;

	if (current->next == NULL)
		return (-1);

	tmp = current->next;
	current->next = tmp->next;
	free(tmp);

	return (1);
}
