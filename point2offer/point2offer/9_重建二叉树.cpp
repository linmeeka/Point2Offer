/*
×¢ÒâÔö¼Óvalid panding
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
class Solution {
public:
	TreeNode* find(const vector<int> &pre, const vector<int> &vin, const int &lp, const int &rp, const int &lv, const int &rv)
	{
		if (lp>rp)
		{
			return NULL;
		}
		int t = pre[lp];
		int cnt = 0;

		for (int i = lv; i <= rv; i++)
		{

			if (vin[i] == t)
				break;
			cnt++;
		}
		TreeNode* now = new TreeNode(t);
		now->left = find(pre, vin, lp + 1, lp + cnt, lv, lv + cnt - 1);
		now->right = find(pre, vin, lp + cnt + 1, rp, lv + cnt + 1, rv);
		return now;
	}
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		int l = 0;
		int r = pre.size();
		TreeNode* res = find(pre, vin, l, r, l, r);
		return res;
	}
};

typedef vector<int> vecint;
int main()
{
	Solution s;
	vecint pre = { 1,2,4,7,3,5,6,8 };
	vecint vin = { 4,7,2,1,5,3,8,6 };
	TreeNode* res = s.reConstructBinaryTree(pre, vin);
	return 0;
}