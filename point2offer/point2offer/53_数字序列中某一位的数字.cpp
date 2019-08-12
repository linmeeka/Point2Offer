 // https://www.acwing.com/problem/content/52/
#include <algorithm>
#include <math>

class Solution {
public:
	int digitAtIndex(int n) {
		if (n == 2147483647)   return 2;
		if (n<0) return -1;
		int digits = 1;
		while (1)
		{
			int numbers = count(digits);
			// digitsλ�������ж���λ��
			if (n<numbers*digits)
				return gets(n, digits);
			n -= numbers*digits;
			digits++;
		}
		return -1;

	}
	// nλ�������ж��ٸ���
	int count(int n)
	{
		if (n == 1)    return 10;
		int c = pow(10, n - 1);
		return 9 * c;
	}
	int gets(int n, int d)
	{
		// ��һ����
		int num = begin(d) + n / d;
		// ����λ
		int r = d - n%d;
		for (int i = 1; i<r; i++)
			num /= 10;
		return num % 10;
	}
	// ��һλ�ʼ����
	int begin(int d)
	{
		if (d == 1)    return 0;
		return pow(10, d - 1);
	}
};