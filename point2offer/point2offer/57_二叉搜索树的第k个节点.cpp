/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
*/
class Solution {
public:
	void findK(TreeNode* root, int k, int &now, TreeNode *&res)
	{
		if (root->left == NULL&&root->right == NULL)
		{
			now++;
			if (now == k)
				res = root;
			return;
		}
		if (root->left)
			findK(root->left, k, now, res);
		now++;
		if (now == k)
		{
			res = root;
			return;
		}
		if (root->right)
			findK(root->right, k, now, res);
		return;
	}
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		if (pRoot == NULL || k == 0)    return nullptr;
		int now = 0;
		TreeNode* res = nullptr;
		findK(pRoot, k, now, res);
		return res;
	}


};