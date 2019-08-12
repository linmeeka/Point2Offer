/*
˼·��ά���������һ���ڵ㣡
��Ҫ�ֳ�����������������Ҫ���������������С�Ŀ�ʼ�����ģ�ÿ�ΰ���С��������ǰ�ġ�
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