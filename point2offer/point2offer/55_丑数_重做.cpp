/*
思路：
能想到的是，每个丑数都是2,3,5的乘积，每次累加新的丑数，就是把原先的*2，*3，*5，找最小的。
问题是要把哪些*2，*3，*5。
res[a]指向的是它乘的最小的数。原理上说每个数都要被2,3,5乘一遍，所以用这个指针遍历。
同时三个if 没有 else，保证了不会出现相同的数
*/

#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		if (index<7)    return index;
		vector<int>res(index, 0);
		res[0] = 1;
		int a = 0;
		int b = 0;
		int c = 0;
		for (int i = 1; i<index; i++)
		{
			res[i] = min(res[a] * 2, min(res[b] * 3, res[c] * 5));
			if (res[i] == res[a] * 2)    a++;
			if (res[i] == res[b] * 3)    b++;
			if (res[i] == res[c] * 5)    c++;
		}
		return res[index - 1];
	}
};

int main()
{
	Solution s;
	s.GetUglyNumber_Solution(10);
	return 0;
}