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

struct node *minvaluenode(struct node *node)
{
    struct node *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minvaluenode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inOrder(struct node *node)
{
    if (node == NULL)
        return;
    inOrder(node->left);
    printf("%d ", node->data);
    inOrder(node->right);
}

int main()
{
    struct node *root;
    root = create(20);
    root->left = create(15);
    root->right = create(30);
    root->left->left = create(10);
    root->left->right = create(17);
    root->left->left->left = create(2);
    root->left->left->right = create(12);
    // printf("\n\t%d \n",root->data);
    // printf("%d ",root->left->data);
    // printf("\t\t%d \n",root->right->data);
    // printf("%d ",root->left->left->data);
    // printf("%d \n",root->left->right->data);
    // printf("%d ",root->left->left->left->data);
    // printf("%d ",root->left->left->right->data);
    printf("\nBefore deletion InOrder of tree : ");
    inOrder(root);
    struct node *deleted_node = deleteNode(root, 15);
    printf("\n\nAfter deletion InOrder of tree : ");
    inOrder(root);
    // printf("\n %d", deleted_node->data);


    // printf("\n\t%d \n",root->data);
    // printf("%d ",root->left->data);
    // printf("\t\t%d \n",root->right->data);
    // printf("%d ",root->left->left->data);
    // printf("%d \n",root->left->right->data);
    // printf("%d ",root->left->left->left->data);
    // printf("%d ",root->left->left->right->data);


    return 0;
}