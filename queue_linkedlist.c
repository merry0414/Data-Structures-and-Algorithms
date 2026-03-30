#include <stdio.h>
#include <stdlib.h>

typedef struct queueNode
{
	int value;
	struct queueNode *next;
}queueNode;


typedef struct 
{
	queueNode *front;
	queueNode *rear;
}queue;

void initQueue(queue *q) 
{
    q -> front = NULL;
    q -> rear = NULL;
}

queueNode *create_node(int val)
{
	queueNode *new_node = (queueNode*)malloc(sizeof(queueNode));
	if(new_node)
	{
		new_node -> value = val;
		new_node -> next = NULL;
	}
	else
	{
		printf("cannot malloc memory\n");
	}
	return new_node;
}

void enqueue(queue *q, int val)
{
	queueNode *new_node = create_node(val); 
	if(new_node == NULL)
	{
		return;
	}
	if(q -> rear == NULL)
	{
		q -> rear = new_node;
	}
	else
	{
		q -> rear -> next = new_node;
		q -> rear = new_node;
	}
	
	if(q -> front == NULL)
	{
		q -> front = new_node;
	}
}


int dequeue(queue *q)
{
	if(q -> front)
	{
		queueNode *temp = q -> front;
		int k = q -> front -> value;
	    q -> front = q -> front -> next;
	    free(temp);
	    if(q -> front == NULL)
	    {
	    	q -> rear = NULL;
		}
		return k;
	}
	else
	{
		return -1;
	}
		
}

int isempty(queue *q) 
{
    return q->front == NULL;
}
