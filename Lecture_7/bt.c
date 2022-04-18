// Binary Tree Implementation

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};


struct node* newnode(int key)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key = key;
    node->left = node->right = NULL;

    return node;
}

void InorderTraversal(struct node* root)
{
    if (root == NULL) {
        return;
    }

    InorderTraversal(root->left);
    printf("%d ", root->key);
    InorderTraversal(root->right);
}

void PreorderTraversal(struct node* root)
{
    if (root == NULL) {
        return;
    }

    printf("%d ", root->key);
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}

struct node* construct(int inorder[], int start, int end,
                int preorder[], int *pIndex)
{
    // base case
    if (start > end) {
        return NULL;
    }
    struct node* node = newnode(preorder[(*pIndex)++]);

    int i;
    for (i = start; i <= end; i++)
    {
        if (inorder[i] == node->key) {
            break;
        }
    }

    node->left = construct(inorder, start, i - 1, preorder, pIndex);

    node->right = construct(inorder, i + 1, end, preorder, pIndex);

    return node;
}

struct node* constructTree(int inorder[], int preorder[], int n)
{
    int pIndex = 0;

    return construct(inorder, 0, n - 1, preorder, &pIndex);
}

void main()
{
    int n;
    printf("Enter the number of elements in inorder/preorder array: ");
    scanf("%d",&n);

    printf("\nInorder Array: \n");
    int inorder[n],preorder[n],i;
    for(i=0;i<n;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&inorder[i]);
    }

    printf("\nPreorder Array: \n");
    for(i=0;i<n;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&preorder[i]);
    }


    struct node* root = constructTree(inorder, preorder, n);

    printf("Tree created successfully\n");
    printf("Traverse the constructed tree\n");
    printf("The inorder traversal is "); InorderTraversal(root);
    printf("\nThe preorder traversal is "); PreorderTraversal(root);
}
