#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};

class Solution {
public:

	void add(string& str, int t)
	{
		string tmp;
		while (t)
		{
			tmp += t % 10 + '0';
			t /= 10;
		}
		reverse(tmp.begin(), tmp.end());
		str += tmp;
		str += ',';
	}
	char * Serialize(TreeNode *root) {

		string str;
		if (!root) return nullptr;
		queue<TreeNode*> q;
		q.push(root);
		add(str, root->val);
		// cout<<str<<endl;
		// return str;
		while (!q.empty())
		{
			TreeNode* n = q.front();
			q.pop();
			if (n->left)
			{
				add(str, n->left->val);
				q.push(n->left);
			}
			else
			{
				str += '#';
				str += ',';
			}
			if (n->right)
			{
				add(str, n->right->val);
				q.push(n->right);
			}
			else
			{
				str += '#';
				str += ',';
			}
		}
		char* c;
		const int len = str.length();
		c = new char[len + 1];
		strcpy(c, str.c_str());
		return c;
	}
	int getNum(string &str, int &tmp)
	{
		if (str.length() <= 0)    return false;
		int s = 0;
		if (str[s] == '#')
		{
			str = str.substr(2, str.length() - 2);
			return false;
		}
		int e = 0;
		tmp = 0;
		for (e = 0; e<str.length(); e++)
		{
			if (str[e] == ',')
				break;
			tmp *= 10;
			tmp += str[e] - '0';
		}
		e++;
		if (e >= str.length() - 1)
			str = "";

		else
			str = str.substr(e, str.length() - e);
		// cout<<str<<endl;
		return true;
	}
	TreeNode* Deserialize(char* st) {
		if (st == NULL || *st == '\0')
		{
			// TreeNode* root=new TreeNode(-1);
			// return root;
			return NULL;
		}
		string str = st;

		//return root;
		TreeNode* root = NULL;
		if (str.length() == 0)
		{
			//root=new TreeNode(-1);
			return root;
		}
		queue<TreeNode*>q;
		int tmp;
		getNum(str, tmp);

		root = new TreeNode(tmp);
		q.push(root);
		while (!q.empty())
		{
			TreeNode* n = q.front();
			q.pop();
			int t = 0;
			if (getNum(str, t))
			{
				TreeNode *l = new TreeNode(t);
				n->left = l;
				q.push(l);
			}
			else
				n->left = NULL;
			if (getNum(str, t))
			{
				TreeNode *r = new TreeNode(t);
				n->right = r;
				q.push(r);
			}
			else
				n->right = NULL;
		}
		return root;
	}
};

int main()
{
	TreeNode *n = new TreeNode(1);
	TreeNode *nl = new TreeNode(2);
	TreeNode *nr = new TreeNode(3);
	n->left = nl;
	n->right = nr;
	Solution s;
	auto a= s.Serialize(n);
	auto res=s.Deserialize(a);
	return 0;
}