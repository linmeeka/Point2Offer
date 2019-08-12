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
		stack<TreeNode*>s;
		vector<vector<int>>res;
		if (!pRoot)    return res;
		s.push(pRoot);
		while (!s.empty())
		{
			stack<TreeNode*> s1 = s;
			stack<TreeNode*> s2;
			stack<TreeNode*> s3;
			vector<int> resTmp;
			while (!s1.empty())
			{
				TreeNode* tmp = s1.top();
				s1.pop();
				resTmp.push_back(tmp->val);
				if (tmp->left)
					s2.push(tmp->left);
				if (tmp->right)
					s2.push(tmp->right);

			}
			if (!resTmp.empty())
				res.push_back(resTmp);
			resTmp.clear();
			while (!s2.empty())
			{
				TreeNode* tmp = s2.top();
				s2.pop();
				resTmp.push_back(tmp->val);
				if (tmp->right)
					s3.push(tmp->right);
				if (tmp->left)
					s3.push(tmp->left);

			}
			if (!resTmp.empty())
				res.push_back(resTmp);
			s = s3;
		}
		return res;
	}

};