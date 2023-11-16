#include "monty.h"


/**
 * f_mul - multiplies the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;	
	int len;
	int result;
	stack_t *temp;

	for (len = 0; current != NULL; len++)	
		current = current->next;
	if (len < 2)
	{
		fprintf(stderr, "L%d: need 2+ values to multiply\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	result = current->next->n * current->n;
	current->next->n = result;
	temp = current->next;
	
	current->next = current->next->next;
	temp->next = NULL;

	free(temp);
}

