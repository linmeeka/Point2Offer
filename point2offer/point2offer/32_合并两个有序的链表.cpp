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
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode* head = new ListNode(0);
		/*
		if(pHead1==NULL&&pHead2==NULL)
		return NULL;
		else if(!pHead1||pHead1->val>pHead2->val)
		{
		head=pHead2;
		pHead2=pHead2->next;
		}
		else if(!pHead2||pHead1->val<pHead2->val)
		{
		head=pHead1;
		pHead1=pHead1->next;
		}*/
		ListNode* now = head;
		while (pHead1&&pHead2)
		{
			if (pHead1->val <= pHead2->val)
			{
				now->next = pHead1;
				pHead1 = pHead1->next;
			}
			else if (pHead1->val>pHead2->val)
			{
				now->next = pHead2;
				pHead2 = pHead2->next;
			}
			now = now->next;
		}
		if (pHead1)
			now->next = pHead1;
		else
			now->next = pHead2;
		return head->next;
	}
};