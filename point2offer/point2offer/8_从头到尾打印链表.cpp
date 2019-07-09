/*
思路：c++11 的reverse可以反转容器。好用！
*/
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> res;
		if (head == nullptr)
			return res;
		ListNode* p = head;
		while (p != nullptr)
		{
			res.push_back(p->val);
			p = p->next;
		}
		reverse(res.begin(), res.end());
		return res;
	}

	// 递归做法
	void find(ListNode* head, vector<int> &res)
	{
		if (head == nullptr)
			return;
		find(head->next, res);
		res.push_back(head->val);
	}
	vector<int> printListFromTailToHead2(ListNode* head) {
		vector<int> res;
		find(head, res);
		return res;
	}
};