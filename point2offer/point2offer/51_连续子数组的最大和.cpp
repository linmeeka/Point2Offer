class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int res = -1;
		int now = 0;
		for (auto i : array)
		{
			now += i;
			if (now>0)
				res = max(res, now);
			else
				now = 0;
		}
		return res;
	}

};