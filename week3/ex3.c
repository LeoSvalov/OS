#include "stdio.h"
#include "stdlib.h"

struct node
{
	int value;
	struct node *next;
};

void print_list(struct node* a)
{
	while(a != NULL){
		printf(" %d",a->value);
		a = a->next;
	}
	printf("\n");
	return;
}

void insert_node(struct node** head, int a_value)
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));

	new_node->value = a_value;
	new_node->next = NULL;
	struct node *tail = *head;
	if (*head == NULL) // case for empty list
	{
		*head = new_node;
		return;
	}
	while(tail->next != NULL){
		tail = tail->next;
	}
	tail->next = new_node;
	return;
}

void delete_node(struct node** head, int a_value){
	struct node* temporary = *head;
	struct node* previous;
	if (temporary != NULL && temporary->value == a_value) // case for 1st element in list
	{
		*head = temporary->next;
		free(temporary);
		return;

	}

	while(temporary != NULL && temporary->value != a_value)
	{
		previous = temporary;
		temporary = temporary->next;
	}

	if (temporary == NULL)
	{
		printf("There is no such element in the list.\n");
		return;
	}
	previous->next = temporary->next;
	free(temporary);
	return;
}

int main(int argc, char const *argv[])
{
	struct node* head = NULL;

	int n;
	printf("Input number of elements of the list:\n");
	scanf("%d/n",&n);
	printf("Input elements:\n");
	int temporary;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d/n",&temporary);
		insert_node(&head,temporary);
	}
	printf("The list:");
	print_list(head);

	printf("Choose element to delete:\n");
	scanf("%d/n",&temporary);
	delete_node(&head,temporary);

	printf("The list:");
	print_list(head);
	return 0;
}