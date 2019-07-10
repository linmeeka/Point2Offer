#include <iostream>
#include <algorithm>

/*
很复杂！！！
要重新做！！！ 
*/
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		ListNode* pre = NULL;
		ListNode* now = pHead;
		while (now != NULL)
		{
			bool flag = false;
			if (now->next&&now->val == now->next->val)
				flag = true;
			if (flag)
			{
				ListNode* ne = now;
				while (ne != NULL&&ne->val == now->val)
				{
					ne = ne->next;
				}
				if (pre == NULL)
					pHead = ne;
				else
					pre->next = ne;
				now = ne;

			}
			else
			{
				pre = now;
				now = now->next;
			}
		}
		return pHead;
	}
};

int main()
{
	ListNode* h = new ListNode(1);
	ListNode* h1 = new ListNode(1);
	ListNode* h2 = new ListNode(2);

	ListNode* h3 = new ListNode(2);
	ListNode* h4 = new ListNode(3);
	h->next = h1;

	h1->next = h2;
	h2->next = h3;
	h3->next = h4;
	Solution s;
	auto res = s.deleteDuplication(h);
	return 0;
}