/*
˼·���ݹ���� ������
ע������������ exponent<=0
*/

class Solution {
public:
	double pow_1(double base, int exponent)
	{
		// ע��0����
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
		// ע�⸺��������
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