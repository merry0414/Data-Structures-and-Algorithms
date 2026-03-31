#define MAXSIZE 100

typedef struct queueArray
{
	int nums [MAXSIZE];
	int front;
	int rear;
}queueArray;

void init(queueArray *q)
{
	q -> front = 0;
	q -> rear= 0;
}

int isfull(queueArray *q)
{
	return((q -> rear + 1) % MAXSIZE == q -> front);
}

int isempty(queueArray *q)
{
	return q -> rear == q -> front;
}

void enqueue(queueArray *q, int val)
{
	if(isfull(q))
	{
		printf("full queue; cannot enqueue");
	}
	else
	{
		q -> rear = (q -> rear + 1) % MAXSIZE;
	    q -> nums[q -> rear] = val;
	}
}

int dequeue(queueArray *q)
{
	if(isempty(q))
	{
		printf("empty queue; cannot dequeue");
		return -1;
	}
	else
	{
		q -> front = (q -> front + 1) % MAXSIZE;
		return q -> nums[q -> front];
	}
}


int queue_length(queueArray *q)
{
	if(q -> front <= q -> rear)
	{
		return q -> rear - q -> front + 1;
	}
	else
	{
		return q -> rear + MAXSIZE - q -> front + 1;
	}
}
