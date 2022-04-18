// Push operation in stack

#include<stdio.h>
#include<stdlib.h>

int n=3;
int s[3],top=0;

int isfull()
{
	if(top>=n)
		return 1;
	else
		return 0;
}

void push(int x)
{
	if (isfull())
	{
		printf("Stack Overflow\n");
		disp();
		exit(0);
	}
	else
	{
		top+=1;
		s[top]=x;
	}
}

void disp()
{
	printf("\nStack elements are:\n");
	for(int i=n;i>0;i--)
		printf("%d\n",s[i]);		
}

void main()
{
	int x;
	while(1)
	{
		printf("Enter element to push: ");
		scanf("%d",&x);
		push(x);
		printf("Element Pushed\n\n");
	}
}
