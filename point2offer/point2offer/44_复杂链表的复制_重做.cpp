/*
˼·���¸�ֵ�Ľڵ����ԭ���б�Ľڵ��
������O��1�����ң�ʵ��O(1)�ķ������ǿ�ԭ������Ϊ��������
*/
/*
struct RandomListNode {
int label;
struct RandomListNode *next, *random;
RandomListNode(int x) :
label(x), next(NULL), random(NULL) {
}
};
*/
typedef RandomListNode node;
class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (!pHead)    return NULL;

		node *p = pHead;
		while (p)
		{
			node *t = new node(p->label);
			t->next = p->next;
			p->next = t;
			p = p->next->next;
		}
		//  return pHead;
		p = pHead;
		while (p)
		{
			node* t = p->next;
			if (p->random)
				t->random = p->random->next;
			//if(!p->next)
			//    break;
			//if(p->next->next)
			p = t->next;
			//else
			//    break;
		}
		//return pHead;
		p = pHead->next;
		node* tmp;
		node *c = pHead;
		while (c->next)
		{
			tmp = c->next;
			c->next = tmp->next;
			c = tmp;
		}
		return p;
	}
};