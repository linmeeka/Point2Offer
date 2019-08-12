class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		int l = 0;
		int r = array.size() - 1;
		int mmin = sum*sum;
		vector<int> res = { sum,sum };
		for (int l = 0; l<array.size(); l++)
		{
			if (array[l]>sum)
				break;
			for (int r = array.size() - 1; r>l; r--)
			{
				if (array[l] + array[r] == sum)
				{
					if (array[l] * array[r]<mmin)
					{
						mmin = array[l] * array[r];
						res[0] = array[l];
						res[1] = array[r];
					}
				}
				else if (array[l] + array[r]<sum)
					break;
			}
		}
		if (res[0] == sum&&res[1] == sum)
			return vector<int>();
		return res;
	}
};