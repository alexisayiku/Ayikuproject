#include "lists.h"
/**
 * delete_nodeint_at_index -  this delete a node in a idx position
 * @head: this defined  pointer to head in function
 * @index:this is  index or position to be added
 * Return: this defined nth node data
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int nodes;
	listint_t *node_before, *node_index = *head, *node_after;

	if (head == NULL || *head == NULL)/*Ask if there is not input*/
		return (-1);

	for (nodes = 0; node_index != NULL; nodes++)/*Count the num of nodes*/
		node_index = node_index->next;
	if (index > nodes)
		return (-1);
	node_index = *head;

	if (index == 0)
	{
		node_after = (*head)->next;
		*head = node_after;
		free(node_index);
		return (1);
	}
	else
	{
		node_before = *head;
		node_after = *head;
		for (nodes = 0; nodes < (index - 1); nodes++)
			node_before = node_before->next;
		for (nodes = 0; nodes < index; nodes++)
			node_index = node_index->next;
		for (nodes = 0; nodes < (index + 1); nodes++)
			node_after = node_after->next;

		node_before->next = node_after;
		free(node_index);
		return (1);
	}
}
