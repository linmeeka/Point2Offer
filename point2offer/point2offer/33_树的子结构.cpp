/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	bool find(TreeNode* p1, TreeNode* p2)
	{
		if (p2 == NULL)
			return true;
		else if (p1 == NULL || p2 == NULL || p1->val != p2->val)
			return false;
		return find(p1->left, p2->left) && find(p1->right, p2->right);
	}
	bool search(TreeNode* p1, TreeNode* p2)
	{
		if (p1 == NULL)
			return false;
		if (p2->val == p1->val)
		{
			if (find(p1, p2))
				return true;
		}
		return search(p1->left, p2) || search(p1->right, p2);
	}
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot2 == NULL)
			return false;
		return search(pRoot1, pRoot2);
	}
};