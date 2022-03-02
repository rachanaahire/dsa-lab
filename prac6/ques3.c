#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
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

int countLeafNode(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return countLeafNode(root->left) + countLeafNode(root->right);
}

int main()
{
    struct node *root;
    root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(9);
    root->left->left->left = create(5);
    // root->left->left->right = create(6);
    // root->left->right->left = create(5);
    // root->left->right->right = create(6);

    printf("Number of leaf Node : %d", countLeafNode(root));

    return 0;
}