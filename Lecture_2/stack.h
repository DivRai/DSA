// Header file for Stack Operations

char push(char a[], int *t, char e, int n)
{
	if (*t<n)
	{
		*t+=1;
		a[*t]=e;
		return '1';
	}
	else
	{
		printf("Stack Overflow\n\n");
		return '0';
	}
}

char pop(char a[], int *t)
{
	if (*t==0)
	{
		printf("Stack Underflow\n\n");
		return '0';
	}
	else
	{
		*t-=1;
		return a[*t+1];
	}
}

void peep(char a[], int *t, int i)
{
	if(*t-i+1<=0)
		printf("Stack underflow\n\n");
	else
		printf("Element at index %d is %c\n",i,a[*t-i+1]);
}

void change(char a[], int*t, char x, int i)
{
	if(*t-i+1<=0)
		printf("Stack underflow\n\n");
	else
	{
		a[*t-i+1]=x;
		printf("New element at index %d is %c\n",i,x);
	}
}
