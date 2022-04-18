#include<stdio.h>
#include<stdlib.h>
#include "cqueue.h"

void main()
{
	int ch;
    while (1)
    {
        printf("\n1.CEnqueue Operation\n");
        printf("2.CDequeue Operation\n");
        printf("3.Display the CQueue\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            cenqueue();
            break;
            case 2:
            cdequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            default:
            printf("Incorrect choice\n");
        } 
    } 
}

