/*
思路：维护序列最后一个节点！
不要分成左右两个树来做，要想中序遍历，从最小的开始找最大的，每次把最小的连到当前的。
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
	void conv(TreeNode *n, TreeNode *&last)
	{
		if (!n)
			return;
		if (n->left)
			conv(n->left, last);
		n->left = last;
		if (last)
			last->right = n;
		last = n;
		if (n->right)
			conv(n->right, last);

	}
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (!pRootOfTree)    return pRootOfTree;
		TreeNode* head = pRootOfTree;
		while (head->left)
			head = head->left;
		TreeNode* last = nullptr;
		conv(pRootOfTree, last);
		return head;
	}
};