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
	while(1)
	{
		int p=pop(s,&top);
		if(p!=0)
			printf("Element popped %d\n",p);
		else
			break;
	}
}
