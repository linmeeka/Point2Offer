/*
leetcode  343
*/

/*
我的解法
dp[n]=max(dp[i-j]*j,dp[i])
init dp[i]=i;
因为每段中间长度绳子都要变成n长度的一部分，所以可以初始化为i
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
书上dp解答
两处不同：
1. dp[i] = max(dp[i - j] * dp[j], dp[i]);
想想也是乘以dp[j]更有道理
2. 内层循环到i/2
因为一半是重复的。 这里能节省不少时间，没有想到，要注意！
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
贪心解法
大于5时，尽可能多划分3
大于4时，尽可能多划分2
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