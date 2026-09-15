#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - frees a listint_t list and sets head to NULL
 * @head: address of the head of the list
 *
 * Return: Nothing
 */
void free_listint2(listint_t **head)
{
	listint_t *current;

	if (head == NULL)
		return;

	while (*head != NULL)
	{
		current = (*head)->next;
		free(*head);
		*head = current;
	}

	*head = NULL;
}
