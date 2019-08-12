/*
s��һ����e�����������ʱ������ڣ���
�����ڻ��ڣ�ֻ�������ж��Ƿ��л�����

�һ�����Ⱥ�һ��Ų��ͷָ�룬����ÿ�ζ���һ���������ĵط��ǻ����
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