// Singly Linked List Insertion, Deletion, Copy and Display Operation

#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
	int data;
	struct Node* next;
};
struct Node* head = NULL;
struct Node *temp;

void InsertAtFirst(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data  = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void InsertAtPos(struct Node** head_ref, int new_data, int pos)
{
	
	temp=(struct Node*)malloc(sizeof(struct Node));
	struct Node *ptr;
	int i;
	temp->data = new_data;
	temp->next=NULL;
	if(pos==0)
	{
		temp->next=head;
		head=temp;
	}
	else
	{
		for(i=0,ptr=head;i<pos-1;i++) 
		{ 
			ptr=ptr->next;
			if(ptr==NULL)
		{
			printf("\nPosition not found:");
		return;
		}
	}
	temp->next =ptr->next ;
	ptr->next=temp;
	}
}
 
void InsertAtLast(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node *last = *head_ref;  
	new_node->data  = new_data;  
	new_node->next = NULL;    
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}  
	while (last->next != NULL)
	last = last->next;    
	last->next = new_node;
	return;
}
 
void display(struct Node* n)
{
	printf("Linked List: ");
	while (n != NULL)
	{
		printf("%d ", n->data);
		n = n->next;
	}
	printf("\n");
}

void deleteNode(struct Node** head_ref, int key)
{
	struct Node *temp = *head_ref, *prev;
	if (temp != NULL && temp->data == key)
	{
		*head_ref = temp->next;
        free(temp);
        return;
    }
	while (temp != NULL && temp->data != key)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return;
	prev->next = temp->next;
	free(temp);
}

struct Node* copyList(struct Node* head)
{
	if (head == NULL)
	{
		return NULL;
	}
	else
	{
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = head->data;
		newNode->next = copyList(head->next);  
		return newNode;
	}
}

void main()
{
	struct Node* dup;
	
	int ch,ele,pos;
	while(1)
	{	
		printf("\nEnter your choice: \n1.Insertion at beginning \n2.Insertion at last \n3.Insertion by position \n4.Deletion \n5.Copy \n6.Display \n7.Quit \n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				printf("\nEnter element you want to insert in beginning: ");
				scanf("%d",&ele);
				InsertAtFirst(&head,ele);
				break;
				
			case 2:
				printf("\nEnter element you want to insert at last: ");
				scanf("%d",&ele);
				InsertAtLast(&head,ele);
				break;

			case 3:
				printf("\nEnter the element you want to insert: ");
				scanf("%d",&ele);
				printf("\nEnter the position to insert (First position will be 0): ");
				scanf("%d",&pos);
				InsertAtPos(&head,ele,pos);
				break;

			case 4:
				printf("Enter element you want to delete: ");
				scanf("%d",&ele);
				deleteNode(&head,ele);
				break;

			case 5:
				dup = copyList(head);
				printf("Duplicate ");
				display(dup);
				break;

			case 6:
				display(head);
				break;

			case 7:
				exit(0);

			default:	
				printf("Invalid Choice\n");
				break;
		}
	} 
}
