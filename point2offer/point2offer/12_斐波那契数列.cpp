/*
µÝ¹é£¬¼ÇÒä»¯ËÑË÷
*/

class Solution {
public:

	int find(vector<int>&f, const int& n)
	{
		int t1, t2;
		if (f[n - 1] == -1)
			t1 = find(f, n - 1);
		else
			t1 = f[n - 1];
		if (f[n - 2] == -1)
			t2 = find(f, n - 2);
		else
			t2 = f[n - 2];
		f[n] = t1 + t2;
		return f[n];
	}
	int Fibonacci(int n) {
		vector<int>f(1000, -1);
		f[0] = 0;
		f[1] = 1;
		if (n == 0) return 0;
		if (n == 1) return 1;
		return find(f, n);
	}
};


/*
dp
*/
class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		int numfn1 = 0, numfn2 = 1;
		int currentnum;
		for (int i = 2; i <= n; ++i) {
			currentnum = numfn1 + numfn2;
			numfn1 = numfn2;
			numfn2 = currentnum;
		}
		return currentnum;
	}
};