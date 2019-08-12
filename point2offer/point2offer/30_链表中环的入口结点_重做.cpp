/*
s走一步，e走两步，相等时不是入口！！
而是在环内，只能用来判断是否有环！！

找环：相等后，一个挪到头指针，两个每次都走一步，相遇的地方是环入口
*/

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
*/
class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)
			return NULL;

		ListNode* s = pHead;
		ListNode *e = pHead;
		while (1)
		{
			if (s == NULL || e == NULL)
				return NULL;
			s = s->next;

			e = e->next;
			if (e == NULL)
				return NULL;
			else
				e = e->next;
			if (s == e)
			{
				s = pHead;
				while (1)
				{
					if (s == e)
						return s;
					s = s->next;
					e = e->next;
				}
			}
		}
		return NULL;
	}
};