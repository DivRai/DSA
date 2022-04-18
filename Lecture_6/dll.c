// Doubly Linked List Insertion, Deletion and Display Operations

#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *prev;
	int info;
	struct node *next;
};


void display(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	p=start;
	printf("\nList is :\n");
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->next;
	}
	printf("\n");
}

struct node *addatbeg(struct node *start,int data)
{
	struct node *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->prev=NULL;
	tmp->next=start;
	start->prev=tmp;
	start=tmp;
	return start;
}

struct node *addatend(struct node *start,int data)
{
	struct node *tmp,*p;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	p=start;
	while(p->next!=NULL)
	{
		p=p->next;
		p->next=tmp;
		tmp->next=NULL;
		tmp->prev=p;
	}
	return start;
}

struct node *addafter(struct node *start,int data,int item)
{
	struct node *tmp,*p;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	p=start;
	while(p!=NULL)
	{
		if(p->info==item)
		{
		        tmp->prev=p;
		        tmp->next=p->next;
		        if(p->next!=NULL)
		                p->next->prev=tmp;
		        p->next=tmp;
		        return start;
		}
		p=p->next;
	}
	printf("\n%d not present in the list\n\n",item);
	return start;
}

struct node *addbefore(struct node *start,int data,int item)
{
	struct node *tmp,*q;
	if(start==NULL )
	{
		printf("\nList is empty\n");
		return start;
	}
	if(start->info==item)
	{
		tmp = (struct node *)malloc(sizeof(struct node));
		tmp->info=data;
		tmp->prev=NULL;
		tmp->next=start;
		start->prev=tmp;
		start=tmp;
		return start;
	}
	q=start;
	while(q!=NULL)
	{
		if(q->info==item)
		{
		tmp=(struct node *)malloc(sizeof(struct node));
		tmp->info=data;
		tmp->prev=q->prev;
		tmp->next = q;
		q->prev->next=tmp;
		q->prev=tmp;
		return start;
		}
		q=q->next;
	}
	printf("\n%d not present in the list\n",item);
	return start;
}

struct node *del(struct node *start,int data)
{
	struct node *tmp;
	if(start==NULL)
	{
		printf("\nList is empty\n");
		return start;
	}
	/*only one node in the list*/
	if(start->next==NULL)
	{
		if(start->info==data)
		{
		    tmp=start;
		    start=NULL;
		    free(tmp);
		    return start;
	    }
		else
		{
		    printf("\nElement %d not found\n",data);
		    return start;
	    }
	}
	/*Deletion of first node*/
	if(start->info==data)
	{
		tmp=start;
		start=start->next;
		start->prev=NULL;
		free(tmp);
		return start;
	}
	/*Deletion in between*/
	tmp=start->next;
	while(tmp->next!=NULL )
	{
		if(tmp->info==data)
		{
		    tmp->prev->next=tmp->next;
		    tmp->next->prev=tmp->prev;
		    free(tmp);
		    return start;
		}
		tmp=tmp->next;
	}
	/*Deletion of last node*/
	if(tmp->info==data)
	{
		tmp->prev->next=NULL;
		free(tmp);
		return start;
	}
	printf("\nElement %d not found\n",data);
	return start;
}

void main()
{
	int ch,data,item;
	struct node *start=NULL;
	while(1)
	{
		printf("\nEnter your choice:\n");
		printf("1. Add at beginning \n2. Add at end \n3. Add after \n4. Add before \n5. Delete \n5. Display \n10. Quit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			start=addatbeg(start,data);
			break;

			case 2:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			start=addatend(start,data);
			break;

			case 3:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element after which to insert : ");
			scanf("%d",&item);
			start=addafter(start,data,item);
			break;

			case 4:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element before which to insert : ");
			scanf("%d",&item);
			start=addbefore(start,data,item);
			break;

			case 5:
			printf("Enter the element to be deleted : ");
			scanf("%d",&data);
			start=del(start,data);
			break;

			case 6:
			exit(0);

			default:
			printf("Invalid choice\n");
		}
	}
}
