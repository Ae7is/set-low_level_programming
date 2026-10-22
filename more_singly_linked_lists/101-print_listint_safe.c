#include "lists.h"

/**
 * print_num - prints a number in a given base with _putchar
 * @n: the number
 * @base: the base, 10 or 16
 */
static void print_num(unsigned long int n, unsigned int base)
{
	if (n >= base)
		print_num(n / base, base);
	_putchar("0123456789abcdef"[n % base]);
}

/**
 * print_node - prints one node as [address] value
 * @node: the node
 * @arrow: 1 to start the line with "-> "
 */
static void print_node(const listint_t *node, int arrow)
{
	long int value;

	if (arrow)
	{
		_putchar('-');
		_putchar('>');
		_putchar(' ');
	}
	_putchar('[');
	_putchar('0');
	_putchar('x');
	print_num((unsigned long int)node, 16);
	_putchar(']');
	_putchar(' ');
	value = node->n;
	if (value < 0)
	{
		_putchar('-');
		value = -value;
	}
	print_num((unsigned long int)value, 10);
	_putchar('\n');
}

/**
 * find_seen - looks for a node among the first count nodes of a list
 * @head: first node of the list
 * @target: the node to look for
 * @count: how many nodes to check
 * Return: the node if found, NULL otherwise
 */
static const listint_t *find_seen(const listint_t *head,
				  const listint_t *target, size_t count)
{
	size_t i;

	if (target == NULL)
		return (NULL);

	for (i = 0; i < count; i++)
	{
		if (head == target)
			return (head);
		head = head->next;
	}

	return (NULL);
}

/**
 * print_listint_safe - prints a listint_t list, even if it has a loop
 * @head: pointer to the first node
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current;
	const listint_t *seen;
	size_t count;

	if (head == NULL)
		exit(98);

	count = 0;
	current = head;
	while (current != NULL)
	{
		print_node(current, 0);
		count++;
		seen = find_seen(head, current->next, count);
		if (seen != NULL)
		{
			print_node(seen, 1);
			break;
		}
		current = current->next;
	}

	return (count);
}
