// Push,Pop,Peep,Change operation using switch case

#include<stdio.h>
#include<stdlib.h>

int push(int a[], int *t, int e, int n)
{
	if (*t<n)
	{
		*t+=1;
		a[*t]=e;
		return 1;
	}
	else
	{
		printf("Stack Overflow\n\n");
		return 0;
	}
}

int pop(int a[], int *t)
{
	if (*t==0)
	{
		printf("Stack Underflow\n\n");
		return 0;
	}
	else
	{
		*t-=1;
		return a[*t+1];
	}
}

void peep(int a[], int *t, int i)
{
	if(*t-i+1<=0)
		printf("Stack underflow\n\n");
	else
		printf("Element at index %d is %d\n",i,a[*t-i+1]);
}

void change(int a[], int*t, int x, int i)
{
	if(*t-i+1<=0)
		printf("Stack underflow\n\n");
	else
	{
		a[*t-i+1]=x;
		printf("New element at index %d is %d\n",i,x);
	}
}

void main()
{
	int n=3;
	int s[n],top=0;
	int ch,i,x1,x,p;
	while(1)
	{
		printf("\nEnter your choice: \n1. Push \n2. Pop \n3. Peep \n4. Change \n5. Quit\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				printf("Enter element to push: ");
				scanf("%d",&x);
				if(push(s,&top,x,n))
					printf("Element pushed\n\n");
				else
					break;
			break;

			case 2:
				p=pop(s,&top);
				if(p!=0)
					printf("Element popped %d\n",p);
				else
					break;
			break;
				
			case 3:
				printf("Enter the index of element: ");
				scanf("%d",&i);
				peep(s,&top,i);
			break;

			case 4:
				printf("Enter the index of element: ");
				scanf("%d",&i);
				printf("Enter new element: ");
				scanf("%d",&x1);
				change(s,&top,x1,i);
			break;
			
			case 5:	
				printf("\nThank You\n");
				exit(0);

			default:
				printf("Invalid choice\n");
				break;
		}
	}
}
