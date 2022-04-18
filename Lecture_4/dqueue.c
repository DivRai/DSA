#include<stdio.h>
#include<stdlib.h>
#include "dqueue.h"
#include "queue.h"

void main()
{
	int ch;
    while (1)
    {
        printf("\n1.Insertion at front Operation\n");
        printf("2.Deletion from rear Operation\n");
        printf("3.Display the DQueue\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            denqueue();
            break;
            case 2:
            ddequeue();
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

