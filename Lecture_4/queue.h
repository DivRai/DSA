// Enqueue and Dequeue in Circular Queue

#define SIZE 100

int Queue[SIZE];
int Front=-1,Rear=-1;

void enqueue()
{
    int insert_item;
    if (Rear == SIZE - 1)
       printf("Overflow\n");
    else
    {
        if (Front == - 1)
       
        Front = 0;
        printf("Element to be inserted in the Queue: ");
        scanf("%d", &insert_item);
        Rear = Rear + 1;
        Queue[Rear] = insert_item;
    }
} 
  
void dequeue()
{
    if (Front == - 1 || Front > Rear)
    {
        printf("Underflow\n");
        return ;
    }
    else
    {
        printf("Element deleted from the Queue: %d\n", Queue[Front]);
        Front = Front + 1;
    }
} 

void show()
{
     
    if (Front == - 1)
        printf("Empty Queue\n");
    else
    {
        printf("Queue: ");
        for (int i = Front; i <= Rear; i++)
            printf("%d ", Queue[i]);
        printf("\n");
    }
} 

