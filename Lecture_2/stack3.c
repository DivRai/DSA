// Pop operation in stack

#include<stdio.h>

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
	int x;
	while(1)
	{
			printf("Enter element to push: ");
			scanf("%d",&x);
			if(push(s,&top,x,n))
				printf("Element pushed\n\n");
			else
				break;
	}
	printf("top is %d\n",top);
	
	int i;
	printf("Enter the index of element: ");
	scanf("%d",&i);
	peep(s,&top,i);

	int x1;
	printf("\nEnter new element: ");
	scanf("%d",&x1);
	change(s,&top,x1,i);
}
