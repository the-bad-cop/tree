#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *left, *right;
} node;
node *newNode(int data)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}
node *createTree(int arr[], int l, int r)
{
    if (l > r)
        return NULL;
    int mid = (l + r) / 2;
    node *root = newNode(arr[mid]);
    root->left = createTree(arr, l, mid - 1);
    root->right = createTree(arr, mid + 1, r);
    return root;
}
void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
void main()
{
    int a[] = {4, 5, 1, 9, 7, 2, 8, 6};
    int n = 8, i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    node *root = createTree(a, 0, n - 1);
    inOrder(root);
}