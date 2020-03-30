#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct Node
{
    int data;
    struct Node *left, *right;
} node;

node *createNode()
{
    int data;
    node *new;
    printf("\nEnter the data:");
    scanf("%d", &data);
    if (data == -1)
        return NULL;
    new = (node *)malloc(sizeof(node));
    new->data = data;
    printf("Enter lchild of %d", data);
    new->left = createNode();
    printf("Enter rchild of %d", data);
    new->right = createNode();
    return new;
}
void preOrder(node *tree)
{
    if (tree != NULL)
    {
        printf("%d", tree->data);
        preOrder(tree->left);
        preOrder(tree->right);
    }
}
void main()
{
    node *root;
    root = createNode();
    printf("\nPrinting\n");
    preOrder(root);
}