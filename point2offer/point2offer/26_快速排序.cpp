/*
leetcode 215
*/
class Solution {
public:
	int findPivot(vector<int> &nums, int l, int r)
	{
		int tmp = nums[l];
		int low = l;
		int high = r;
		while (low<high)
		{
			while (low < high && nums[high] >= tmp)
				high--;
			nums[low] = nums[high];
			while (low < high && nums[low] <= tmp)
				low++;
			nums[high] = nums[low];
		}
		nums[low] = tmp;
		return low;
	}
	void quickSort(vector<int>& nums, int l, int r)
	{
		if (l >= r)
			return;

		int p = findPivot(nums, l, r);
		quickSort(nums, l, p - 1);
		quickSort(nums, p + 1, r);
	}
	int findKthLargest(vector<int>& nums, int k) {
		quickSort(nums, 0, nums.size() - 1);

		return nums[nums.size() - k];
	}
};


/*
leetcode 148 Á´±í¿ìÅÅ

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
	void quickSort(ListNode* head, ListNode* end)
	{
		if (head == NULL || end == NULL || head == end)
			return;
		ListNode *s = head;
		ListNode *e = head->next;
		while (e != NULL)
		{
			if (e->val<head->val)
			{
				s = s->next;
				int t = e->val;
				e->val = s->val;
				s->val = t;
			}
			e = e->next;
		}
		int t = head->val;
		head->val = s->val;
		s->val = t;
		//cout<<s->val<<endl;
		quickSort(head, s);
		quickSort(s->next, e);
	}
	ListNode* sortList(ListNode* head) {
		ListNode* end = head;
		while (end->next != NULL)
			end = end->next;
		quickSort(head, end);
		return head;
	}
};