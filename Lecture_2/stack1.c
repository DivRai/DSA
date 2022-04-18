// Push operation in stack using pointer

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
	printf("Stack elements are:\n");
	for(int i=n;i>0;i--)
		printf("%d\n",s[i]);
}
