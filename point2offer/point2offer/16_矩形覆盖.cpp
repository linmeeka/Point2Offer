
/*
斐波那契数列dp
f(n)从最右划出一个格子，可能数+f(n-1)
再划出一个，现在有两个空闲格子，这两个格子的有两种组合方式，但是一种和一个格子时相同，因此+f(n-2)
后续的和前面已经计算的对称，不用再加
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