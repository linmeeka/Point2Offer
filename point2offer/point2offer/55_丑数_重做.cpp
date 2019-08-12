/*
˼·��
���뵽���ǣ�ÿ����������2,3,5�ĳ˻���ÿ���ۼ��µĳ��������ǰ�ԭ�ȵ�*2��*3��*5������С�ġ�
������Ҫ����Щ*2��*3��*5��
res[a]ָ��������˵���С������ԭ����˵ÿ������Ҫ��2,3,5��һ�飬���������ָ�������
ͬʱ����if û�� else����֤�˲��������ͬ����
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