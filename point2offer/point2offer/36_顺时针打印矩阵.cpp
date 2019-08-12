class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> res;
		int m = matrix.size();
		if (m == 0)
			return res;
		int n = matrix[0].size();
		if (n == 0)
			return res;
		int i = 0;
		int j = 0;
		while (m>0 && n>0)
		{
			for (int t = 0; t<n; t++)
			{
				res.push_back(matrix[i][j]);
				j++;
			}
			m--;
			if (m <= 0)    break;
			j--;
			i++;
			for (int t = 0; t<m; t++)
			{
				res.push_back(matrix[i][j]);
				i++;
			}
			n--;
			if (n <= 0)    break;
			i--;
			j--;
			for (int t = 0; t<n; t++)
			{
				res.push_back(matrix[i][j]);
				j--;
			}
			m--;
			if (m <= 0)    break;
			j++;
			i--;
			for (int t = 0; t<m; t++)
			{
				res.push_back(matrix[i][j]);
				i--;
			}
			n--;
			if (n <= 0)    break;
			j++;
			i++;
		}
		return res;
	}
};