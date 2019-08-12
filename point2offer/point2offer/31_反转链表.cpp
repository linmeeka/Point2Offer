/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		ListNode* a = pHead;
		ListNode* b = pHead->next;
		ListNode* c = pHead->next->next;
		if (c == NULL)
		{
			pHead->next->next = pHead;
			pHead->next = NULL;
			return c;
		}
		while (c->next != NULL)
		{
			ListNode* t = c->next;
			b->next = a;
			a = b;
			c->next = b;
			b = c;
			c = t;
		}
		c->next = b;
		pHead->next = NULL;
		return c;

	}
};