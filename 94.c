#include <stdio.h>
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

static void	pushBack( struct TreeNode *root, int **result, int *size )
{
	if (root == NULL)
		return ;
	pushBack(root->left, result, size);
	*result = realloc(*result, sizeof(int) * (*size + 1));
	(*result)[*size] = root->val;
	(*size)++;
	pushBack(root->right, result, size);
}

int	*inorderTraversal( struct TreeNode *root, int *returnSize )
{
	int	size = 0;
	int	*result = NULL;

	pushBack(root, &result, &size);
	*returnSize = size;
	return (result);
}

static void	initRoot( struct TreeNode **root )
{
	*root = malloc(sizeof(struct TreeNode));
	(*root)->val = 1;
	(*root)->left = malloc(sizeof(struct TreeNode));
	(*root)->left->val = 2;
	(*root)->left->left = malloc(sizeof(struct TreeNode));
	(*root)->left->left->val = 4;
	(*root)->left->left->left = NULL;
	(*root)->left->left->right = NULL;
	(*root)->left->right = malloc(sizeof(struct TreeNode));
	(*root)->left->right->val = 5;
	(*root)->left->right->left = NULL;
	(*root)->left->right->right = NULL;
	(*root)->right = malloc(sizeof(struct TreeNode));
	(*root)->right->val = 3;
	(*root)->right->left = NULL;
	(*root)->right->right = malloc(sizeof(struct TreeNode));
	(*root)->right->right->val = 6;
	(*root)->right->right->left = NULL;
	(*root)->right->right->right = NULL;
}

int	main( void )
{
	struct TreeNode	*root;
	int				*result, size = 0;

	initRoot(&root);
	printf("=================== RESULT ===================\n");
	result = inorderTraversal(root, &size);
	for (int i = 0; i < size; i++)
		printf("%d ", result[i]);
	printf("\n");
	delete(root);
	free(result);
	return (0);
}
