// Insertion in Linked List

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

void display(struct node *first)
{
	struct node *save;
	save = first;
	do
	{
		printf("%d, ",save->info);
		save=save->link;
	}
	while(save!=NULL);
	printf("\n");
}

struct node *insert(int x,struct node *first)
{
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	if(new==NULL)
	{
		printf("Overflow\n");
		return first;
	}
	else
	{
		new->info=x;
		new->link=first;
		return new;
	}
}

void main()
{
	struct node *first, *second, *third;
	first = (struct node *)malloc(sizeof(struct node));
	second = (struct node *)malloc(sizeof(struct node));
	third = (struct node *)malloc(sizeof(struct node));

	first->info=1;
	first->link=second;

	second->info=2;
	second->link=third;

	third->info=3;
	third->link=NULL;

	display(first);

	int num;
	printf("Enter number you want to insert: ");
	scanf("%d",&num);
	first=insert(num,first);
	printf("\nAfter insertion\n");
	display(first);
}
