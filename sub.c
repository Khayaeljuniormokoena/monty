#include "monty.h"

/**
 * f_sub - subtracts the top element of the stack from the second top element.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;
	int nodes = 0;
	int difference;
	stack_t *temp;

	for (nodes = 0; current != NULL; nodes++)
		current = current->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, need at least two values\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;

	difference = current->next->n - current->n;

	current->next->n = difference;
	temp = current->next;

	current->next = current->next->next;

	temp->next = NULL;
	free(temp);
}
