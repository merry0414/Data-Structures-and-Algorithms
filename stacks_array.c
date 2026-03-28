#include <stdio.h>

#define MAXSIZE 100
typedef struct 
{
 int value[MAXSIZE];
 int top;
}stack;

void init(stack *s)
{
	s -> top = -1;
}

int isfull(stack *s)
{
	if((s -> top) == MAXSIZE - 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int isempty(stack *s)
{
	if((s -> top) == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(stack *s, int val)
{
	if(isfull(s))
	{
		printf("stack is full");
	}
	else
	{
		s -> value[++(s -> top)] = val;
	}
}

int pop(stack *s)
{
	if(isempty(s))
	{
		printf("stack is empty; cannot pop");
		return -1;
	}
	else
	{
		return s -> value[(s -> top)--];
	}
}
