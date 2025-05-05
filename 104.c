#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

struct TreeNode
{
	int				val;
	struct TreeNode	*left;
	struct TreeNode	*right;
};

static void	delete( struct TreeNode *root )
{
	if (root == NULL)
		return ;
	delete(root->left);
	delete(root->right);
	free(root);
}

int	maxDepth( struct TreeNode *root )
{
	int	left, right;

	if (root == NULL)
		return (0);
	left = maxDepth(root->left);
	right = maxDepth(root->right);
	return (left > right ? left + 1 : right + 1);
}

static void	initRoot( struct TreeNode **root )
{
	*root = malloc(sizeof(struct TreeNode));
	(*root)->val = 3;
	(*root)->left = malloc(sizeof(struct TreeNode));
	(*root)->left->val = 9;
	(*root)->left->left = NULL;
	(*root)->left->right =NULL;
	(*root)->right = malloc(sizeof(struct TreeNode));
	(*root)->right->val = 20;
	(*root)->right->left = malloc(sizeof(struct TreeNode));
	(*root)->right->left->val = 15;
	(*root)->right->right = malloc(sizeof(struct TreeNode));
	(*root)->right->right->val = 7;
	(*root)->right->left->left = NULL;
	(*root)->right->left->right = NULL;
	(*root)->right->right->left = NULL;
	(*root)->right->right->right = NULL;
}

int	main( void )
{
	struct TreeNode	*root;

	initRoot(&root);
	printf("=================== RESULT ===================\n");
	printf("RESULT = %d\n", maxDepth(root));
	delete(root);
	return (0);
}
