// Enqueue and Dequeue in Circular Queue

#define SIZE 100

int CQueue[SIZE];
int front=-1,rear=-1;

int isFull() 
{
	if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) 
		return 1;
	else
		return 0;
}

int isEmpty() 
{
	if (front == -1) 
		return 1;
	else
		return 0;
}

void cenqueue() 
{
	int e;
	printf("Enter element you want to insert: ");
	scanf("%d",&e);
	if (isFull())
		printf("\n Queue is full!! \n");
	else 
	{
		if (front == -1) 
			front = 0;
		rear = (rear + 1) % SIZE;
		CQueue[rear] = e;
		printf("Inserted element %d\n", e);
	}
}

int cdequeue() 
{
	int e;
	if (isEmpty()) 
	{
		printf("\n Queue is empty !! \n");
		return -1;
	} 
	else 
	{
		e = CQueue[front];
		if (front == rear) 
		{
			front = -1;
			rear = -1;
		} 
		else
			front = (front + 1) % SIZE;
	printf("Deleted element %d\n", e);
	return (e);
	}
}

void display() 
{
	int i;
	if (isEmpty())
		printf("Empty Queue\n");
	else 
	{
		printf("Front = %d\n", front);
		printf("CQueue: ");
		for (i = front; i != rear; i = (i + 1) % SIZE) 
		{
			printf("%d ", CQueue[i]);
		}
		printf("%d ", CQueue[i]);
		printf("\nRear = %d\n", rear);
	}
}

