#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int p)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr->left = NULL;
    ptr->data = p;
    ptr->right = NULL;
    return ptr;
}

int count(struct node *tree)
{
    int c = 1; 
    if (tree == NULL)
        return 0;
    else
    {
        c += count(tree->left);
        c += count(tree->right);
        return c;
    }
}

int main()
{
    struct node *root;
    root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    // root->left->left->left = create(5);
    // root->left->left->right = create(6);
    // root->left->right->left = create(6);
    // root->left->right->right = create(6);

    int c = count(root); 
    printf("Number of nodes in the given tree are %d \n", c);
}