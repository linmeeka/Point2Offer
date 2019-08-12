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
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		// 注意K是无符号，无符号0-1=max_int
		if (pListHead == NULL || k == 0)
			return NULL;
		ListNode* s = pListHead;
		ListNode* e = pListHead;
		for (int i = 0; i<k - 1; i++)
		{
			if (!e->next)
				return NULL;
			e = e->next;
		}
		while (e->next != NULL)
		{
			e = e->next;
			s = s->next;
		}
		return s;
	}

};