// Polynomial representation of 2D array
#include<stdio.h>
#include<string.h>
#include <ctype.h>

int array[4][4];
void fun(char *s)
{
	int n,i,x,y,j,coff,mul,num,xpow,ypow;

	n =strlen(s);

	for(i=0;i<n;i++)
	{
		xpow = 0;
		ypow = 0;
		while(s[i] != '+' && i<n)
		{
			mul = 1;
			if(isdigit(s[i]))
			{
				num = s[i] - '0';
				coff = num;
				i++;
				while(isdigit(s[i]))
				{
					num = s[i] - '0';
					coff = (coff*10) + (num);
					i++;	
				}
			}
			else if(s[i] == 'x')
			{
				i++;
				xpow = 1;
				if(isdigit(s[i]))
				{
					xpow = s[i] - '0';
					i++;
				}
				if(s[i] == 'y')
				{
					i++;
					ypow = s[i] - '0';
					i++;
				}
			}
			else if(s[i] == 'y')
			{
				i++;
				xpow = 0;
				if(isdigit(s[i]))
				{
					ypow = s[i] - '0';
					i++;
				}
				else
				{
					ypow = 1;
					i++;
				}
			}
			if(s[i] == ' ')
			{
				array[xpow][ypow] = coff;
				i++;
			}
		}
	}
}

void main()
{
	int i,j,array1[4][4], array2[4][4],ans[4][4];
	char m1[100] = "21x3 +2x2y1 +3x1y2 +3y3 +1x1 +1y1 ";
	fun(m1);
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			array1[i][j] = array[i][j];
			array[i][j] = 0;
		}
	}
	printf("\nFor eq1\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d ", array1[i][j]);
		}
		printf("\n");
	}
	char m2[100] = "20x3 +8x2y1 +9x1y2 +2y3 +3x1 +3y1 ";
	fun(m2);
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			array2[i][j] = array[i][j];	
			array[i][j] = 0;
		}
	}
	printf("\nFor eq2\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d ", array2[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			ans[i][j] = array1[i][j] + array2[i][j];
		}
	}
	printf("\neq1:- \n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(ans[i][j] == 0)
			{
				continue;
			}
			printf(" %dx^%dy^%d +", array1[i][j],i,j);
		}
	}
	printf("\n");
	printf("\neq2:- \n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(ans[i][j] == 0)
			{
				continue;
			}
			printf(" %dx^%dy^%d +", array2[i][j],i,j);
		}
	}
	printf("\n");
	printf("\nans:- \n");	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(ans[i][j] == 0)
			{
				continue;
			}
			printf(" %dx^%dy^%d +", ans[i][j],i,j);
		}
	}
	printf("\n");
}
