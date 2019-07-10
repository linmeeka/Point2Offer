/*
leetcode 327
����ȫһ��
˼·��������ڵ����ĸ��ǵ�ǰ�ڵ㣬ֱ�Ӱ�next->val��val��next=next->next
ĩβ�ڵ�Ļ���Ҫ˳�����
ͷ�ڵ�Ļ�ֱ�Ӹ�ֵΪ�գ�Ϊɶĩβ�ڵ㲻��ֱ�Ӹ�Ϊ�գ�
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	void deleteNode(ListNode* node) {
		node->val = node->next->val;
		if (!node->next->next)
			node->next = NULL;
		else
			node->next = node->next->next;
	}
};