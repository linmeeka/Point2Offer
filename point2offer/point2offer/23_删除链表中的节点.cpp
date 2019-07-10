/*
leetcode 327
不完全一样
思路：用这个节点后面的覆盖当前节点，直接把next->val给val，next=next->next
末尾节点的话需要顺序查找
头节点的话直接赋值为空（为啥末尾节点不能直接赋为空？
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