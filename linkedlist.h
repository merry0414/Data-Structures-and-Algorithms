#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node
{
	int val;
	struct Node *next;
}Node;
Node *createnode(int data);
void tail_append(Node **head, int data);
void head_append(Node **head, int data);
void traverse(Node *head);
void delete(Node **head, int value);
void all_delete(Node **head);

#endif
