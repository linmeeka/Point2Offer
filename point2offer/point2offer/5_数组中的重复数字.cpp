
/*
时间o(n)，空间o(1)
思路：逐个交换元素位置，把下标为i的元素交换到下标为n[i]的位置，当出现n[i]=n[n[i]]，
说明有重复，每次循环到n[i]=i停止，此时说明已经到正确位置
*/
class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		for (int i = 0; i<length; i++)
		{
			int t = numbers[i];
			if (t>length - 1 || t<0)
				return false;
		}
		for (int i = 0; i<length; i++)
		{
			while (numbers[i] != i)
			{
				if (numbers[i] == numbers[numbers[i]])
				{
					*duplication = numbers[i];
					return true;
				}
				int t = numbers[i];
				numbers[i] = numbers[numbers[i]];
				numbers[t] = t;
			}
		}
		return false;

	}
};


/*
leetcode 287.
不改变原数组的值，不增加额外空间
时间：O(nlogn),空间O(1)
思路：在一定范围[l,r]内若有重复，则在这个范围内的元素数大于r-1+1
使用二分，查找这一范围
*/
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int l = 1;
		int r = nums.size() - 1;
		int res = 0;
		while (l<r)
		{
			int mid = (l + r) / 2;
			int cntl = count(nums, l, mid);
			int cntr = count(nums, mid + 1, r);
			if (cntl>mid - l + 1)
				r = mid;
			else if (cntr>r - mid)
				l = mid + 1;
		}
		return l;
	}
	int count(const vector<int>& nums, int l, int r)
	{
		int cnt = 0;
		for (auto num : nums)
		{
			if (num >= l&&num <= r)
				cnt++;
		}
		return cnt;
	}
};