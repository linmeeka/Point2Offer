/*
思路：递归计算 快速幂
注意特殊用例： exponent<=0
*/

class Solution {
public:
	double pow_1(double base, int exponent)
	{
		// 注意0！！
		if (exponent == 0)
			return 1;
		if (exponent == 1)
			return base;
		else
		{
			double t = pow_1(base, exponent / 2);
			if (exponent % 2 == 0)
				return t*t;
			else
				return t*t*base;
		}
	}
	double Power(double base, int exponent) {
		bool flag = false;
		// 注意负数！！！
		if (exponent<0)
		{
			flag = true;
			exponent *= -1;
		}
		double res = pow_1(base, exponent);
		if (flag)
			res = 1.0 / res;
		return res;
	}
};