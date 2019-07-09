/*
1+2^0+2^1+...+2^{n-2}=2^{n-1}
*/

class Solution {
public:
	int jumpFloorII(int number) {
		int res = 1;
		for (int i = 2; i <= number; i++)
			res += pow(2, i - 2);
		return res;
		// return pow(2,number-1);
	}
};

