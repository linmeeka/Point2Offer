/*
思路：用快排里的partion
每次轴左边的最小的几个，如果这些数多于k，则返回，否则继续排序
*/
#include <set>
using namespace std;
class Solution {
public:
	void partion(vector<int>& input, int k, int l, int r)
	{
			
		if (l>r)    return;
		int index = input[r];
		int s = l;
		int e = r;
		while (s<e)
		{
			while (s<e&&input[s] <= index)
				s++;
			swap(input[s], input[e]);
			while (s<e&&input[e] >= index)
				e--;
			swap(input[s], input[e]);
		}
		if (s == k)
			return;
		else if (s>k)
			partion(input, k, l, s - 1);
		else
			partion(input, k - s, s, r);

	}

	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> res;
		if (input.size()<k)    return res;
		partion(input, k, 0, input.size() - 1);

		for (int i = 0; i<k; i++)
		{
			res.push_back(input[i]);
		}
		return res;
		
	}
};

/*
用set，不改变原数组，O(NK)
注意multiset<int, greater<int>>,含有重复元素，从大到小排序
*/

class Solution {
public:

	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> res;
		if (input.size()<k)
			return res;
		multiset<int, greater<int>> s;
		multiset<int, greater<int>>::iterator it;
		for (auto i : input)
		{
			if (s.size()<k)
				s.insert(i);
			else
			{
				it = s.begin();
				if (*it>i)
				{
					s.erase(it);
					s.insert(i);
				}
			}
		}

		for (it = s.begin(); it != s.end(); it++)
			res.push_back(*it);
		return res;
		return res;
	}
};