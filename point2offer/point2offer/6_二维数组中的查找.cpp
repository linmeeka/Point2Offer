/*
剑指offer
思路：从左下或右上搜索，每次排除一行或一列
*/
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int m = array.size();
		int n = array[0].size();
		int cx = n - 1;
		int cy = 0;
		while (cx >= 0 && cy<m)
		{
			if (array[cy][cx]<target)
				cy++;
			else if (array[cy][cx]>target)
				cx--;
			else if (array[cy][cx] == target)
				return true;
		}
		return false;
	}
};
