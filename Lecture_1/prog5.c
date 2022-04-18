// Simple array to Sparse array

#include<stdio.h>
int max(int a[10], int size)
{
	int i,maxa;
	maxa = a[0];
	for(i=1;i<size;i++)
	{
		if(maxa<a[i])
		{
			maxa = a[i];
		}
	}
	return maxa;
}

void main()
{
	int i,j,row,col,crow,ccol,k,m,n;
	k=0;
	printf("Enter total number of Elemnt:- ");
	scanf("%d", &ccol);
	int a[10][10],c[3][ccol];
	int temp[ccol];
	for(j=0;j<ccol;j++)
	{
		printf("Enter row number:- ");
		scanf("%d", &c[0][j]);
		printf("Enter colume number:- ");
		scanf("%d", &c[1][j]);
		printf("Enter element:- ");
		scanf("%d", &c[2][j]);
	}
	printf("\nYou enter a below matrix:- \n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<ccol;j++)
		{
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	for(j=0;j<ccol;j++)
	{
		temp[j] = c[0][j];
	}
	row = max(temp,ccol)+1;
	
	for(j=0;j<ccol;j++)
	{
		temp[j] = c[1][j];
	}
	col = max(temp,ccol)+1;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			a[i][j] = 0;
		}
		printf("\n");
	}

	for(j=0;j<ccol;j++)	
	{
		m = c[0][j];
		n = c[1][j];
		a[m][n] = c[2][j];
	}
	printf("\nmatrix is:- \n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
