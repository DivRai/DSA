// Insertion at front and Deletion from rear in Double Ended Queue

#define SIZE 100

int DQueue[SIZE];
int f=-1,r=-1;

int isEmpty() 
{
	if (f == 0 && r == SIZE - 1 || f == r + 1) 
		return 1;
	else
		return 0;
}

// Insertion at front
void denqueue() 
{
	int e;
	printf("Enter element you want to insert: ");
	scanf("%d",&e);
	if((f==0 && r==SIZE-1) || (f==r+1))  
    {  
        printf("\nQueue is full\n");  
    }  
	else if((f==-1) && (r==-1))  
    {  
        f=r=0;  
        DQueue[f]=e;  
    }  
    else if(f==0)  
    {  
        f=SIZE-1;  
        DQueue[f]=e;  
    }  
    else  
    {  
        f=f-1;  
        DQueue[f]=e;  
    } 
 	printf("Element inserted %d\n",e);	
}

// Deletion from rear
int ddequeue() 
{
	if((f==-1) && (r==-1))  
    {  
        printf("Deque is empty");  
    }  
    else if(f==r)  
    {  
        printf("The deleted element is %d\n", DQueue[r]);  
        f=-1;  
        r=-1;  
          
    }  
     else if(r==0)  
     {  
         printf("The deleted element is %d\n", DQueue[r]);  
         r=SIZE-1;  
     }  
     else  
     {  
          printf("The deleted element is %d\n", DQueue[r]);  
          r=r-1;  
     }  
}

void display()  
{  
    int i=f;  
    printf("Elements: ");  
      
    while(i!=r)  
    {  
        printf("%d ",DQueue[i]);  
        i=(i+1)%SIZE;  
    }  
     printf("%d\n",DQueue[r]);  
}  

