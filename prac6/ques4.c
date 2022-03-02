#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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


int count(struct node *tree)
{
    int c = 1; //Node itself should be counted
    if (tree == NULL)
        return 0;
    else
    {
        c += count(tree->left);
        c += count(tree->right);
        return c;
    }
}

bool isComplete(struct node *root, int index, int number_nodes)
{
    if (root == NULL)
        return (true);

    if (index >= number_nodes)
        return (false);

    return (isComplete(root->left, 2 * index + 1, number_nodes) &&
            isComplete(root->right, 2 * index + 2, number_nodes));
}

int main()
{
    struct node *root;
    root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(9);
    root->right->left = create(4);
    root->right->right = create(9);
    root->left->left->left = create(5);
    root->left->left->right = create(6);

    int node_count = count(root);
    int index = 0;

    if (isComplete(root, index, node_count))
        printf("The Binary Tree is complete\n");
    else
        printf("The Binary Tree is not complete\n");
    return (0);
}
