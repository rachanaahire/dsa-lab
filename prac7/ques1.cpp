#include <stdio.h>
#include <process.h>
#include <stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
} * newnode, *ptr, *root, *temp;
node *createNode(int p)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = p;
    newnode->left = newnode->right = NULL;
    return newnode;
}
node *insertNode(node *np, int key)
{
    if (np == NULL)
    {
        return createNode(key);
    }
    else
    {
        if (key < np->data)
        {
            np->left = insertNode(np->left, key);
        }
        else if (key > np->data)
        {
            np->right = insertNode(np->right, key);
        }
        else
        {
            return np;
        }
    }
}
node *getMinvalue(node *np)
{
    node *current = np;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
node *deleteNode(node *np, int key)
{
    if (np == NULL)
    {
        return np;
    }
    if (key < np->data)
    {
        np->left = deleteNode(np->left, key);
    }
    else if (key > np->data)
    {
        np->right = deleteNode(np->right, key);
    }
    else
    {
        if (np->left == NULL)
        {
            temp = np->right;
            free(np);
            return temp;
        }
        else if (np->right == NULL)
        {
            temp = np->left;
            free(np);
            return temp;
        }
        else
        {
            temp = getMinvalue(np->right);
            np->data = temp->data;
            np->right = deleteNode(np->right, temp->data);
        }
        return np;
    }
}
int inorder(node *np)
{
    if (np != NULL)
    {
        inorder(np->left);
        printf(" %d", np->data);
        inorder(np->right);
    }
    return 0;
}
int main()
{
    int inf, choice, del;
    root = NULL;
    do
    {
        printf(" \n Press 1 to insert an element ");
        printf(" \n Press 2 to delete an element ");
        printf(" \n Press 3 for traversal ");
        printf("\n Press 4 for exit ");
        system("pause ");
        printf(" \n Enter your choice ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter the info of the node: ");
            scanf("%d", &inf);
            root = insertNode(root, inf);
            break;

        case 2:
            printf("\n Enter the element to be deleted ");
            scanf("%d", &del);
            root = deleteNode(root, del);
            break;

        case 3:
            inorder(root);
            break;

        case 4:
            exit(0);
        default:
            printf("\n Wrong Choice ");
            break;
        }
    } while (choice != 4);
    return 0;
}
