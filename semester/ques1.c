#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct tree
{
    struct tree *left;
    int data;
    struct tree *right;
};

struct tree *root;
struct tree *ptr;

struct tree *create(int p)
{
    ptr = malloc(sizeof(struct tree));
    ptr->left = NULL;
    ptr->data = p;
    ptr->right = NULL;
    return ptr;
}

int doubleOrderTraversal(struct tree *node)
{
    if (node == NULL)
    {
        return 0;
    }
    printf("%d \t", node->data);
    doubleOrderTraversal(node->left);
    printf("%d \t", node->data);
    doubleOrderTraversal(node->right);
}

bool isStrictBinaryTree(struct tree *node)
{
    if (node->left == NULL && node->right == NULL)
    {
        return (true);
    }
    else if (node->left != NULL && node->right != NULL)
    {
        return (true);
    }
    else
    {
        return (false);
    }

    return (isStrictBinaryTree(node->left) && isStrictBinaryTree(node->right));
}

int main()
{
    root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->right->left = create(4);
    root->right->right = create(5);
    root->right->left->left = create(6);
    root->right->left->right = create(7);

    int x;
    int data;
    do
    {
        printf("\n\nEnter 1 for Double order traversal\n");
        printf("Enter 2 to see if strict binary tree\n");
        scanf("%d", &x);

        switch (x)
        {
        case 1:
            doubleOrderTraversal(root);
            break;
        case 2:
            if (isStrictBinaryTree(root))
            {
                printf("\nTRUE");
            }
            else
            {
                printf("\nFALSE");
            }
            break;
        default:
            break;
        }
    } while (x);

    return 0;
}