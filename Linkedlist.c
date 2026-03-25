#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int val;
	struct Node *next;
}Node;

// create a new node for a linkedlist; need a value for this node
Node *createnode(int data)
{
	Node *new_node = (Node*)malloc(sizeof(Node));
	if(new_node == NULL)
	{
		printf("Failed to allocate memory");
		exit(1);
	}
	else
	{
		new_node -> val = data;
		new_node -> next = NULL;
	}
	return new_node;
}

//link the node to the tail; need a value for this node, the head of this Linkedlist

void tail_append(Node **head, int data)
{
	Node *new_node = createnode(data);
	
	if(*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		Node *temp = *head;
		while(temp -> next)
		{
			temp = temp -> next; 
		}
		temp -> next = new_node;
	}
}

//link the node to the head; need a value for this node, the head of this Linkedlist
void head_append(Node **head, int data)
{
	Node *new_node = createnode(data);
	if(*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		new_node -> next = *head;
		*head = new_node;
	}
}

//traverse the given Linkedlist; need the head of this Linkedlist
void traverse(Node *head)
{
	while(head)
	{
		printf("%d\n",head -> val);
		head = head -> next;
	}  
}

//delete a node from the Linkedlist; need the head of this Linkedlist, the value that need to delete
void delete(Node **head, int value)
{
	int isfound = 0;
	Node *temp = *head;
	Node *pre_temp = NULL;
	while(temp)
	{
		if(temp -> val == value && temp != *head)
		{
			pre_temp -> next = temp -> next;
			isfound = 1;
			free(temp);
			break;
		}
		else if(temp == *head)
		{
			*head = temp -> next;
			free(temp);
			isfound = 1;
			break;
		}
		pre_temp = temp;
		temp = temp -> next;
	}
	if(!isfound)
	{
		printf("Not Found. Fail to delete.");
	}
}
