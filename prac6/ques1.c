#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

int search(char arr[], int strt, int end, char value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
}

struct node *newNode(char data)
{
    struct node *node = malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

struct node *createTree(char inorder_arr[], char preorder_arr[], int inStrt, int inEnd)
{
    static int preIndex = 0;

    if (inStrt > inEnd)
        return NULL;

    struct node *tNode = newNode(preorder_arr[preIndex++]);
    if (inStrt == inEnd)
        return tNode;

    int inIndex = search(inorder_arr, inStrt, inEnd, tNode->data);

    tNode->left = createTree(inorder_arr, preorder_arr, inStrt, inIndex - 1);
    tNode->right = createTree(inorder_arr, preorder_arr, inIndex + 1, inEnd);

    return tNode;
}

void inOrder(struct node *node)
{
    if (node == NULL)
        return;
    inOrder(node->left);
    printf("%c ", node->data);
    inOrder(node->right);
}

void postOrder(struct node *node)
{
    if (node == NULL)
        return;
    postOrder(node->left);
    postOrder(node->right);
    printf(" %c", node->data);
}

void preOrder(struct node *node)
{
    if (node == NULL)
        return;
    printf(" %c", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

int main()
{
    char inorder_arr[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char preorder_arr[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    int len = sizeof(inorder_arr);
    struct node *root = createTree(inorder_arr, preorder_arr, 0, len - 1);

    printf("Inorder of the constructed tree is \n");
    inOrder(root);
    printf("\n\nPreOrder of the constructed tree is \n");
    preOrder(root);
    printf("\n\nPostOrder of the constructed tree is \n");
    postOrder(root);
}
