#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - deletes the head node of a listint_t list
 * @head: address of the head of the list
 *
 * Return: data of the deleted node, or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *current;
	int n;

	if (head == NULL || *head == NULL)
		return (0);

	current = *head;
	n = current->n;
	*head = current->next;
	free(current);

	return (n);
}
