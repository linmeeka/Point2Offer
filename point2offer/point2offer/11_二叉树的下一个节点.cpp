
struct TreeLinkNode {
int val;
struct TreeLinkNode *left;
struct TreeLinkNode *right;
struct TreeLinkNode *next;
TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

}
};

class Solution {
public:

	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		// 有右子树，下一个就是右子树的第一个，也就是最左边的叶子
		if (pNode->right != NULL)
		{
			TreeLinkNode* res = pNode->right;
			while (res->left != NULL)
				res = res->left;
			return res;
		}
		// 没有右子树，找到包含它为左子树的那个子树。返回这个子树的根节点
		while (pNode->next != NULL)
		{
			if (pNode == pNode->next->left)
				return pNode->next;
			pNode = pNode->next;
		}
		return NULL;
	}
};