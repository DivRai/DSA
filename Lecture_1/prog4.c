// Sparse array to Simple array

#include<stdio.h>
void main()
{
	int i,j,row,col,crow,ccol,k,m,n;
	k=0;
	printf("Enter total number of Row:- ");
	scanf("%d", &row);
	printf("Enter total number of Coloum:- ");
	scanf("%d", &col);
	int a[row][col],c[3][col*row];
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("Enter (%d,%d) element:- ", i,j);
			scanf("%d", &a[i][j]);
		}
	}
	printf("\nYou enter a below matrix:- \n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	k=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(a[i][j]!=0)
			{
				c[0][k] = i;
				c[1][k] = j;
				c[2][k] = a[i][j];
				k++;
			}
		}
		printf("\n");
	}
	printf("\nSparse matrix:- \n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<k;j++)
		{
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
}
