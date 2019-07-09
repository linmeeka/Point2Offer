/*
思路：位运算
flag用于check每一位是否是1
注意： 符号为不算在内！使用位运算，不要用/2 ！
时间复杂度： int位数次
*/
class Solution {
public:
	int  NumberOf1(int n) {
		int res = 0;
		int flag = 1;
		while (flag)
		{
			if (n&flag)
				res++;
			flag <<= 1;
		}
		return res;
	}
};

/*
思路: 一个整数减一，相当于把这个整数从最右的1开始取反。减一后再和原数与运算，相当于把最右的1变成0
因此每次这么操作一下，就数了一个1
时间复杂度: 1的个数次	
*/
class Solution {
public:
	int  NumberOf1(int n) {
		int res = 0;
		while (n)
		{
			n = n&(n - 1);
			res++;
		}
		return res;
	}
};