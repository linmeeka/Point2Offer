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
	void find(vector<vector<int>> &res, vector<int> &now,
		TreeNode* root, int num, int &nown)
	{
		if (!root)    return;
		if (!root->left&&!root->right)
		{
			if (root->val + nown == num)
			{
				now.push_back(root->val);
				res.push_back(now);
				now.pop_back();
			}
			return;
		}
		else
		{
			now.push_back(root->val);
			nown += root->val;
			if (root->left)
				find(res, now, root->left, num, nown);
			if (root->right)
				find(res, now, root->right, num, nown);
			nown -= root->val;
			now.pop_back();
		}
		return;
	}
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		int nown = 0;
		vector<vector<int>> res;
		vector<int>now;
		find(res, now, root, expectNumber, nown);
		return res;
	}
};