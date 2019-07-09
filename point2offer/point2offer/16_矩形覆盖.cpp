
/*
쳲���������dp
f(n)�����һ���һ�����ӣ�������+f(n-1)
�ٻ���һ�����������������и��ӣ����������ӵ���������Ϸ�ʽ������һ�ֺ�һ������ʱ��ͬ�����+f(n-2)
�����ĺ�ǰ���Ѿ�����ĶԳƣ������ټ�
*/
class Solution {
public:
	int rectCover(int number) {
		int t0 = 1;
		int t1 = 1;
		if (number == 1)    return 1;
		if (number == 0)    return 0;
		int res = 0;
		for (int i = 2; i <= number; i++)
		{
			res = t0 + t1;
			t0 = t1;
			t1 = res;
		}
		return res;
	}
};