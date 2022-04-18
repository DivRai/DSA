// Check whether string is palindrome or not using stack

#include <stdio.h>
#include "stack.h"

void main()
	{
	int n=5, s[n],top=0;
	char a[n];

	printf("Enter a Numerical string\n");
	scanf("%s",a);

	push(s,&top,e);

	for(int i=0;i<n;i++)
	{
		while(a[i]!='c')
		{
			push(s,&top,a[i]);
		}
		while(a[i]==pop(s,&top));
		if(a[i]==" " && pop(s,&top)=='e')
			printf("String is palindrome\n");
		else
			printf("String is not palindrome\n");
	}
}
