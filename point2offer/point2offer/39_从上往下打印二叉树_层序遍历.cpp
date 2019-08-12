/*
层序遍历
这样写可以分开每层
*/

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
	vector<int> PrintFromTopToBottom(TreeNode* root) {

		queue<TreeNode*>q;
		queue<TreeNode*>q1;

		vector<int> res;
		if (!root)    return res;
		q.push(root);
		while (!q.empty())
		{
			q1 = q;
			queue<TreeNode*>q2;
			while (!q1.empty())
			{
				TreeNode* tmp = q1.front();
				q1.pop();
				res.push_back(tmp->val);
				if (tmp->left)
					q2.push(tmp->left);
				if (tmp->right)
					q2.push(tmp->right);
			}
			q = q2;
		}
		return res;
	}
};


/*
不分开每层
*/
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
	vector<int> PrintFromTopToBottom(TreeNode* root) {

		queue<TreeNode*>q;

		vector<int> res;
		if (!root)    return res;
		q.push(root);
		while (!q.empty())
		{
			TreeNode* tmp = q.front();
			q.pop();
			res.push_back(tmp->val);
			if (tmp->left)
				q.push(tmp->left);
			if (tmp->right)
				q.push(tmp->right);
		}
		return res;
	}
};