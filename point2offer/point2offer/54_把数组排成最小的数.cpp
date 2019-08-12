/*
解法二：比较sa + sb<sb + sa;
把要比较的两个小数字拼接成小串比较！
*/
//
//class Solution {
//public:
//	static bool cmp(int &a, int &b)
//	{
//		string sa = to_string(a);
//		string sb = to_string(b);
//		return sa + sb<sb + sa;
//	}
//	string PrintMinNumber(vector<int> numbers) {
//		sort(numbers.begin(), numbers.end(), cmp);
//		string res;
//		for (auto i : numbers)
//			res += to_string(i);
//		return res;
//	}
//};

/*
解法一：自己写比较函数
*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//class Solution {
//public:

	static bool cmp(int &a,int &b)
	{
		//string sa = tostring(a);
		//string sb = tostring(b);
		string sa = to_string(a);
		string sb = to_string(b);
		/*if (sa.length() == 1 && sb.length() == 1)
			return a < b;
		if (sa.length() == 1)
		{
			for (auto s : sb)
			{
				if (a < s - '0')
					return true;
				else if (a>s - '0')
					return false;
			}
			return true;
		}
		if (sb.length() == 1)
		{
			for (auto s : sa)
			{
				if (b < s - '0')
					return false;
				else if (b>s - '0')
					return true;
			}
			return true;
		}*/
		int l = min(sa.length(), sb.length());
		for (int i = 0; i < l; i++)
		{
			int ta = sa[i] - '0';
			int tb = sb[i] - '0';
			if (ta < tb)
			{
				return true;
			}
			else if (ta>tb)
			{
				return false;
			}
			else
			{
				if (i == sa.length() - 1 && i == sb.length() - 1)
					return true;
				else if (i == sa.length() - 1)
				{
					if (sb[i + 1] - '0' < tb)
						return false;
					else
						return true;
				}
				else if (i == sb.length() - 1)
				{
					if (sa[i + 1] - '0' < ta)
						return true;
					else
						return false;
				}
			}
		}
		return true;
	}
	void fun(vector<int> &v)
	{
		sort(v.begin(), v.end(), cmp);

	}
	
	
//};

int main()
{
	vector<int> v = { 3,5 };
	//vector<int> v = { 3,32,321 };
	//Solution s;
	//s.fun(v);
	fun(v);
	return 0;
}