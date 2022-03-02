#include <stdio.h>
#include <stdlib.h>
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

int preorder(struct tree *node)
{
	if (node == NULL)
		return 0;
	else
	{
		printf("  %d", node->data);
		preorder(node->left);
		preorder(node->right);
		return 0;
	}
}

int postorder(struct tree *node)
{
	if (node == NULL)
		return 0;
	else
	{
		postorder(node->left);
		postorder(node->right);
		printf(" %d", node->data);
		return 0;
	}
}

int inorder(struct tree *node)
{
	if (node == NULL)
		return 0;
	else
	{
		inorder(node->left);
		printf(" %d", node->data);
		inorder(node->right);
		return 0;
	}
}

int main()
{
	root = create(1);
	root->left = create(2);
	root->right = create(3);
	root->left->left = create(4);
	root->left->left->left = create(5);

	printf("\n Preorder traversal of binary tree ");
	preorder(root);
	printf("\n Inorder traversal of binary tree ");
	inorder(root);
	printf("\n Postorder traversal of binary tree ");
	postorder(root);
	return 0;
}
