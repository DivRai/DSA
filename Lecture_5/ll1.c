// Simple Linked List Insertion Operations

#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data;
    struct Node *next;
};
int calcSize(struct Node* node){
    int size=0;

    while(node!=NULL){
        node = node->next;
        size++;
    }
    return size;
}

void insm(int pos, int data, struct Node** head)
{
    int size = calcSize(*head);

    if(pos<1 || size < pos) 
    { 
        printf("Can't insert, %d is not a valid position\n",pos); 
    } 
    else 
    { 
        struct Node* temp = *head; 
        struct Node* newNode = (struct Node*) 
        malloc(sizeof(struct Node)); 
        newNode->data = data;
        newNode->next = NULL;

        while(--pos)
        {
            temp=temp->next;
        }
        newNode->next= temp->next;
        temp->next = newNode;
    }
}

void insb(struct Node** head, int data){

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = *head;

    *head = newNode;
}

void inse(struct Node** head, int data){

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    if(*head==NULL){
        *head = newNode;
        return;
    }

    struct Node* temp = *head;

    while(temp->next!=NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display(struct Node* node)
{

    while(node!=NULL){
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
}

void main()
{
    struct Node* head = NULL;

    int ch,e,pos;
    while (1)
    {
        printf("\n1.Insert at beginning operation\n");
        printf("2.Insert at end operation\n");
		printf("3.Insert in middle operation\n");
        printf("4.Display the Queue\n");
        printf("5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
				printf("Enter element you want to insert: ");
				scanf("%d",&e);
				insb(head,e);
            break;

            case 2:
				printf("Enter element you want to insert: ");
				scanf("%d",&e);
		        inse(head,e);
            break;

			case 3:
				printf("Enter element you want to insert: ");
				scanf("%d",&e);
				printf("Enter the position at which you want to insert: ");
				scanf("%d",&pos);
		        insm(pos,e,head);
            break;

            case 4:
            	display(head);
            break;

            case 5:
            	exit(0);
			break;

            default:
            printf("Incorrect choice\n");
        } 
    }
}
