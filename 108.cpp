#include <vector>
#include <iostream>
#include <algorithm>

struct TreeNode
{
	int 		val;
	TreeNode	*left;
	TreeNode	*right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
	~TreeNode() { delete(left); delete(right); }
};

static TreeNode	*ok( std::vector<int> &nums, int start, int end )
{
	if (start > end)
		return NULL;
	int			mid = start + (end - start) / 2;
	TreeNode	*root = new TreeNode(nums[mid]);
	root->left = ok(nums, start, mid - 1);
	root->right = ok(nums, mid + 1, end);
	return root;
}

TreeNode	*sortedArrayToBST( std::vector<int> &nums )
{
	return ok(nums, 0, nums.size() - 1);
}

static void	printBST( TreeNode *root )
{
	if (root == NULL)
		return ;
	printBST(root->left);
	std::cout << root->val << " ";
	printBST(root->right);
}

int	main()
{
	std::vector<int>	test = { -10, -3, 0, 5, 9 };
	TreeNode			*result;

	std::cout << std::endl << "=================== RESULT ===================" << std::endl;
	result = sortedArrayToBST(test);
	printBST(result);
	std::cout << std::endl;
	delete result;
	return 0;
}
