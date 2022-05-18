#include "main.h"

/**
 * addNode - adds a new node at the beginning of a l_list list
 *
 * @head: reference to head of linked list
 * @str: string to be added on new node
 * Return: address of new head;
 */

l_list *addNode(l_list **head, char *str)
{
	l_list *newNode;
	char *newStr;

	if (!str)
		return (NULL);
	newNode = malloc(sizeof(l_list));
	if (!newNode)
	{
		perror("Malloc failed\n");
		exit(errno);
	}
	newStr = _strdup(str);
	if (!newStr)
	{
		perror("Malloc failed\n");
		exit(errno);
	}
	newNode->string = newStr;
	newNode->next = *head;
	*head = newNode;
	return (*head);
}
/**
 * addNodeEnd - adds a node at the end of list
 *
 * @head: head node of the list
 * @str: string to be added to list
 * Return: address of new node
 */

l_list *addNodeEnd(l_list **head, char *str)
{
	l_list *newNode;
	l_list *last = *head;
	char *newStr;

	if (!str)
		return (NULL);
	newNode = malloc(sizeof(l_list));
	if (!newNode)
	{
		perror("Malloc failed\n");
		exit(errno);
	}
	newStr = _strdup(str);
	if (!newStr)
	{
		free(newNode);
		perror("Malloc failed\n");
		exit(errno);
	}
	newNode->string = newStr;
	newNode->next = NULL;
	if (!*head)
	{
		*head = newNode;
		return (newNode);
	}
	while (last->next)
		last = last->next;
	last->next = newNode;
	return (last);
}

/**
 * list_len - returns the number of elements in a linked list
 *
 * @h: head of linked list
 * Return: number of elements in list_t
 */

size_t list_len(l_list *h)
{
	register unsigned int count = 0;

	while (h)
	{
		h = h->next;
		count++;
	}
	return (count);
}

/**
 * printList - prints all elements of a l_list list
 *
 * @h: pointer to head of list
 * Return: number of elements
 */
size_t printList(const l_list *h)
{
	register int count = 0;

	while (h)
	{
		write(STDOUT_FILENO, h->string, _strlen(h->string));
		newLine();
		h = h->next;
		count++;
	}

	return (count);
}

/**
 * deleteNodeAtIndex - deletes node at index
 *
 * @head: double pointer to head of list
 * @index: index of node to be deleted
 * Return: 1 if success, -1 if fail
 */
int deleteNodeAtIndex(l_list **head, unsigned int index)
{
	l_list *current;
	l_list *next;

	register uint i;

	if (!head || !(*head))
		return (-1);
	current = *head;
	if (!index)
	{
		*head = current->next;
		free(current);
		return (1);
	}
	for (i = 0; current && i < index - 1; i++)
		current = current->next;
	if (!current || !(current->next))
		return (-1);
	next = current->next->next;
	free(current->next->string);
	free(current->next);
	current->next = next;
	return (1);
}
