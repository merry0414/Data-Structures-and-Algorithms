#include <stdio.h>
#include <stdlib.h>

typedef struct stacknode
{
	int value;
	struct stacknode *next;
}stackNode;

stackNode *createNode(int val)
{
	stackNode *new_node = (stackNode *)malloc(sizeof(stackNode));
	if(new_node)
	{
		new_node -> value = val;
	    new_node -> next = NULL;
	}
	else
	{
		printf("cannot malloc memory");
	}
	return new_node; 
}


void push(stackNode **head, int val)
{
	stackNode *new_node = createNode(val);
	if(new_node == NULL)
	{
		return;
	}
	if(*head)
	{
		new_node -> next = *head;
		*head = new_node;
	}
	else
	{
		*head = new_node;
	}
}

int pop(stackNode **head)
{
	if(*head)
	{
		int k = (*head) -> value;
		stackNode *temp = *head;
		*head = (*head) -> next;
		free(temp);
		return k;
	}
	else
	{
		printf("empty stack; illegal operation");
		return -1;
	}
}
