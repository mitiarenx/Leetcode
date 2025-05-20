#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
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

static bool	ok( struct TreeNode *left, struct TreeNode *right )
{
	if ((left == NULL && right != NULL) || (left != NULL && right == NULL))
		return (false);
	if (left == NULL && right == NULL)
		return (true);
	if (left->val != right->val)
		return (false);
	return (ok(left->left, right->right) && ok(left->right, right->left));
}

bool	isSymetric( struct TreeNode *root )
{
	if (root == NULL)
		return (true);
	return (ok(root->left, root->right));
}

static void	initRoot( struct TreeNode **root )
{
	*root = malloc(sizeof(struct TreeNode));
	(*root)->val = 1;
	(*root)->left = malloc(sizeof(struct TreeNode));
	(*root)->left->val = 2;
	(*root)->left->left = malloc(sizeof(struct TreeNode));
	(*root)->left->left->val = 3;
	(*root)->left->right = malloc(sizeof(struct TreeNode));
	(*root)->left->right->val = 4;
	(*root)->right = malloc(sizeof(struct TreeNode));
	(*root)->right->val = 2;
	(*root)->right->left = malloc(sizeof(struct TreeNode));
	(*root)->right->left->val = 4;
	(*root)->right->right = malloc(sizeof(struct TreeNode));
	(*root)->right->right->val = 3;
	(*root)->left->left->left = NULL;
	(*root)->left->left->right = NULL;
	(*root)->left->right->left = NULL;
	(*root)->left->right->right = NULL;
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
	if (isSymetric(root))
		printf("They're symetric\n");
	else
		printf("NOOOOO\n");
	delete(root);
	return (0);
}
