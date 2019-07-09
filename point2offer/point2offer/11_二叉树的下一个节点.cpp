
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
		// ������������һ�������������ĵ�һ����Ҳ��������ߵ�Ҷ��
		if (pNode->right != NULL)
		{
			TreeLinkNode* res = pNode->right;
			while (res->left != NULL)
				res = res->left;
			return res;
		}
		// û�����������ҵ�������Ϊ���������Ǹ�������������������ĸ��ڵ�
		while (pNode->next != NULL)
		{
			if (pNode == pNode->next->left)
				return pNode->next;
			pNode = pNode->next;
		}
		return NULL;
	}
};