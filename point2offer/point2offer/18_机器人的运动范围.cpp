class Solution {
public:
	int dir[4][2] = { 1,0,-1,0,0,1,0,-1 };
	bool check(const int& threshold, const int& rows, const int& cols,
		const int& nowx, const int& nowy,
		vector<vector<bool>>& vis, int &res)
	{
		if (nowx<rows&&nowx >= 0 && nowy<cols&&nowy >= 0 && !vis[nowx][nowy])
		{
			int x = nowx;
			int y = nowy;
			int tmp = 0;
			while (x)
			{
				tmp += x % 10;
				x /= 10;
			}
			while (y)
			{
				tmp += y % 10;
				y /= 10;
			}
			if (tmp <= threshold)
			{
				vis[nowx][nowy] = 1;
				res++;
				return true;
			}
		}
		return false;
	}
	void search(const int& threshold, const int& rows, const int& cols,
		const int& nowx, const int& nowy, int &res,
		vector<vector<bool>>& vis)
	{


		for (int i = 0; i<4; i++)
		{
			int nextx = nowx + dir[i][0];
			int nexty = nowy + dir[i][1];
			if (check(threshold, rows, cols, nextx, nexty, vis, res))
				search(threshold, rows, cols, nextx, nexty, res, vis);
		}
		return;
	}
	int movingCount(int threshold, int rows, int cols)
	{
		if (rows<1 || cols<1)
			return 0;

		int res = 0;

		vector<vector<bool>> vis(rows, vector<bool>(cols, false));
		check(threshold, rows, cols, 0, 0, vis, res);
		search(threshold, rows, cols, 0, 0, res, vis);
		return res;
	}
};