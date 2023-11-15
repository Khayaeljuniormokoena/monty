#include "monty.h"

/**
 * f_add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_add(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, need at least two values\n", counter);

		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	int sum = current->n + current->next->n;

	current->next->n = sum;
	stack_t *temp = current->next;

	current->next = current->next->next;

	temp->next = NULL;
	free(temp);
}
