#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int item)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = item;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *newnode, int key)
{
    if (key < newnode->data)
        newnode->left = insert(newnode->left, key);
    else if (key > newnode->data)
        newnode->right = insert(newnode->right, key);
    return newnode;
}

void inOrder(struct node *node)
{
    if (node == NULL)
        return;
    inOrder(node->left);
    printf("%c ", node->data);
    inOrder(node->right);
}

int main()
{
    struct node *tree = malloc(sizeof(struct node));
    struct node *newnode = create(50);

    tree = insert(newnode, 50);
    tree = insert(newnode, 15);
    tree = insert(newnode, 62);
    tree = insert(newnode, 5);
    tree = insert(newnode, 20);
    tree = insert(newnode, 58);
    tree = insert(newnode, 91);
    tree = insert(newnode, 3);
    tree = insert(newnode, 8);
    tree = insert(newnode, 37);
    tree = insert(newnode, 60);
    tree = insert(newnode, 24);

    inOrder(tree);
    return 0;
}