/*
思路：维护一个最大堆和最小堆，放小的一半和大的一半。
堆可用红黑树，也就是set
*/
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include<functional>
using namespace std;

class Solution {
public:
	multiset<int> s2;
	multiset<int, greater<int>> s1;
	void Insert(int num)
	{
		int l = s1.size() + s2.size();
		multiset<int, greater<int>>::iterator it1 = s1.begin();
		multiset<int>::iterator it2 = s2.begin();

		if (l % 2)
		{
			if (*it1>num)
			{
				int t = *it1;
				s1.erase(it1);
				s1.insert(num);
				s2.insert(t);
			}
			else
				s2.insert(num);
		}
		else
		{
			if (!s2.empty() && *it2<num)
			{
				int t = *it2;
				s2.erase(it2);
				s2.insert(num);
				s1.insert(t);
			}
			else
				s1.insert(num);
		}
	}

	double GetMedian()
	{
		int l = s1.size() + s2.size();
		multiset<int, greater<int>>::iterator it1 = s1.begin();
		multiset<int>::iterator it2 = s2.begin();
		if (l % 2)
			return *it1;
		else
			return double((*it1 + *it2)) / 2.0;

	}

};

int main()
{
	Solution s;
	vector<int> v = { 5,2,3,4,1,6,7,0,8 };
	for (auto i : v)
	{
		s.Insert(i);
		auto res=s.GetMedian();
	}
	return 0;
}