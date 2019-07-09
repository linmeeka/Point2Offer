#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
/*
存在重复元素，注意用例如{4,5,6,7,8,1,1,2,2,3,4}
*/

/*
leetcode 153, AC代码
用例弱，存在重复元素：[1,0,1,1,1]时无法通过
这种情况要用顺序查找
*/
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
			int l = 0;
			int r = rotateArray.size() - 1;
			if (r == 0)
				return rotateArray[0];
			if (r == 1)
				return min(rotateArray[0], rotateArray[1]);
			int res = 0;
			while (l <= r)
			{
				int mid = (l + r) / 2;
				if (mid == 0&& rotateArray[mid]<rotateArray[mid + 1] /*|| mid == rotateArray.size() - 1&& rotateArray[mid]<rotateArray[mid - 1] || rotateArray[mid - 1]>=rotateArray[mid] && rotateArray[mid + 1]>=rotateArray[mid]*/)
				{
					res = mid;
					break;
				}
				if (rotateArray[r]<rotateArray[mid])
					l = mid + 1;
				else if (rotateArray[l]>rotateArray[mid])
					r = mid - 1;
			
				else
				{
					res = l;
					break;
				}
			}
			return rotateArray[res];
	}
};

/*
牛客网强用例AC
*/

class Solution {
public:
	int minNumberInRotateArray(vector<int>& nums) {
		int l = 0;
		int r = nums.size() - 1;
		if (r == 0)
			return nums[0];
		if (r == 1)
			return min(nums[0], nums[1]);
		int res = 0;
		while (nums[l] >= nums[r])
		{
			if (r - l == 1)
			{
				res = r;
				break;
			}
			int mid = (l + r) / 2;
			if (nums[l] == nums[r] && nums[mid] == nums[l])
				return find(nums, l, r);
			if (nums[l] <= nums[mid])
				l = mid;
			else if (nums[r] >= nums[mid])
				r = mid;
		}
		return nums[res];
	}
	int find(vector<int> nums, int l, int r)
	{
		int res = nums[l];
		for (int i = l; i <= r; i++)
			res = min(nums[i], res);
		return res;
	}
};
int main()
{
	Solution s;
	vector<int>a = { 5,1,2,3,4};
	int res=s.minNumberInRotateArray(a);
	return 0;
}