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

bool	isSameTree( struct TreeNode *p, struct TreeNode *q )
{
	if ((p == NULL && q != NULL) || (q == NULL && p != NULL))
		return (false);
	if (p == NULL && q == NULL)
		return (true);
	if (p->val != q->val)
		return (false);
	return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}

int	main( void )
{
	struct TreeNode	*p = malloc(sizeof(struct TreeNode));
	p->val = 1;
	p->left = malloc(sizeof(struct TreeNode));
	p->left->val = 2;
	p->left->left = NULL;
	p->left->right = NULL;
	p->right = NULL;

	struct TreeNode	*q = malloc(sizeof(struct TreeNode));
	q->val = 1;
	q->right = malloc(sizeof(struct TreeNode));
	q->right->val = 2;
	q->right->left = NULL;
	q->right->right = NULL;
	q->left = NULL;

	printf("=================== RESULT ===================\n");
	if (isSameTree(p, q))
		printf("They're the same\n");
	else
		printf("NOOOOO\n");
	delete(p);
	delete(q);
	return (0);
}
