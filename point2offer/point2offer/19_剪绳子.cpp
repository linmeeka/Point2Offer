/*
leetcode  343
*/

/*
�ҵĽⷨ
dp[n]=max(dp[i-j]*j,dp[i])
init dp[i]=i;
��Ϊÿ���м䳤�����Ӷ�Ҫ���n���ȵ�һ���֣����Կ��Գ�ʼ��Ϊi
*/
class Solution {
public:
	int integerBreak(int n) {
		vector<int> dp(n + 1, 0);
		dp[0] = 0;
		dp[1] = 1;

		for (int i = 2; i <= n; i++)
		{
			if (i != n)
				dp[i] = i;
			for (int j = 0; j <= i; j++)
			{
				dp[i] = max(dp[i - j] * j, dp[i]);
			}
		}
		return dp[n];
	}
};

/*
����dp���
������ͬ��
1. dp[i] = max(dp[i - j] * dp[j], dp[i]);
����Ҳ�ǳ���dp[j]���е���
2. �ڲ�ѭ����i/2
��Ϊһ�����ظ��ġ� �����ܽ�ʡ����ʱ�䣬û���뵽��Ҫע�⣡
*/
class Solution {
public:
	int integerBreak(int n) {
		vector<int> dp(n + 1, 0);
		dp[0] = 0;
		dp[1] = 1;

		for (int i = 2; i <= n; i++)
		{
			if (i != n)
				dp[i] = i;
			for (int j = 0; j <= i / 2; j++)
			{
				dp[i] = max(dp[i - j] * dp[j], dp[i]);
			}
		}
		return dp[n];
	}
};

/*
̰�Ľⷨ
����5ʱ�������ܶ໮��3
����4ʱ�������ܶ໮��2
*/
class Solution {
public:
	int integerBreak(int n) {
		if (n == 0)    return 0;
		if (n == 1)    return 0;
		if (n == 2)    return 1;
		if (n == 3)    return 2;

		int num1 = n / 3;
		if (n - num1 * 3 == 1)
			num1--;
		int num2 = (n - num1 * 3) / 2;
		int res1 = pow(3, num1);
		int res2 = pow(2, num2);
		return res1*res2;

	}
};