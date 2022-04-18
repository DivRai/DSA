// Write a program to calculate address of element in 2D array
#include<stdio.h>
void main()
{
	int ba,r,c,i,j,m;
	printf("Enter base address: ");
	scanf("%d",&ba);
	printf("\nEnter number of rows and columns in matrix: ");
	scanf("%d%d",&r,&c);
	printf("\nEnter index of element whose address you want to find: ");
	scanf("%d%d",&i,&j);
	printf("Matrix is row major(1) or column major(0): ");
	scanf("%d",&m);

	int add;
	if(m)
		add = ba + ((i-1)*c+(j-1))*4;
	else
		add = ba + ((j-1)*r+(i-1))*4;
	printf("Address of element at index [%d][%d] is %d\n",i,j,add);	
}
