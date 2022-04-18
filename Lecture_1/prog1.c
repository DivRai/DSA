// Write a program to calculate address of element in 1D array
#include<stdio.h>
void main()
{
	int ba,ind,i;
	printf("Enter base address: ");
	scanf("%d",&ba);
	printf("Enter index of element whose address you want to find: ");
	scanf("%d",&ind);

	int add;
	add = ba + 4*(ind-1);
	printf("Address of element at index %d is %d\n",ind,add);	
}
