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
	vector<vector<int> > Print(TreeNode* pRoot) {
		queue<TreeNode*>q;
		queue<TreeNode*>q1;

		vector<vector<int>> res;
		if (!pRoot)    return res;
		q.push(pRoot);
		while (!q.empty())
		{
			q1 = q;
			queue<TreeNode*>q2;
			vector<int> resTmp;
			while (!q1.empty())
			{
				TreeNode* tmp = q1.front();
				q1.pop();
				resTmp.push_back(tmp->val);
				if (tmp->left)
					q2.push(tmp->left);
				if (tmp->right)
					q2.push(tmp->right);
			}
			res.push_back(resTmp);
			q = q2;
		}
		return res;
	}

};