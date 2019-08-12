/*
ʱ��O(n)���ռ�O(n)��map�ⷨ
*/
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		map<int, int> m;
		int l = numbers.size();
		for (auto i : numbers)
		{
			if (m.find(i) != m.end())
			{
				m[i]++;
				if (m[i]>l / 2)
					return i;
			}
			else
			{
				m[i] = 1;
				if (m[i]>l / 2)
					return i;
			}
		}
		return 0;
	}
};

/*
ʱ��O(n)���ռ�O(1)
ʹ��һ��������¼����Ԫ�س��ֵĴ���
��ͬ+1����ͬ-1��Ԫ�ء�
�����ִ������ڵ���1�ľ���
��Ϊcount-1�Ĵ����������count+1�Ĵ������������������Ԫ�أ�һ����coutn>=1
*/
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.size() == 0)    return 0;
		int count = 1;
		int num = numbers[0];
		for (int i = 1; i<numbers.size(); i++)
		{
			if (count == 0)
			{
				num = numbers[i - 1];
				count = 1;
			}
			if (numbers[i] == num)
				count++;
			else
				count--;
		}
		if (count >= 1)    return num;

		return 0;
	}
};

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int partion(vector<int> &numbers, int l, int r)
	{
		if (l > r)
			return 0;

		int index = numbers[r];
		int s = l;
		int e = r;
		while (s<e)
		{
			while (s<e&&numbers[s] <= index)
				s++;
			swap(numbers[s], numbers[e]);
			while (s<e&&numbers[e] >= index)
				e--;
			swap(numbers[s], numbers[e]);
		}
//		numbers[s] = index;
		if (s == (numbers.size()) / 2)
			return numbers[s];
		else if (s>(numbers.size()) / 2)
			return partion(numbers, l, s-1);
		else
			return partion(numbers, s+1, r);
	}
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int res= partion(numbers, 0, numbers.size() - 1);
		int n = 0;
		for (auto i : numbers)
		{
			if (i == res)
				n++;
		}
		if (n > numbers.size() / 2)
			return res;
		else
			return 0;
	}
};

int main()
{
	vector<int> v = { 1,2,3,2,4,2,5,2,3 };
	Solution s;
	int res=s.MoreThanHalfNum_Solution(v);
	
	return 0;
}