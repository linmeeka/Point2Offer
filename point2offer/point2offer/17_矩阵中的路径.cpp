#include <iostream>
#include<vector>
#include <string>
using namespace std;

class Solution {
public:
	int dir[4][2] = { 1,0,-1,0,0,1,0,-1 };
	bool chech(char* matrix, const string &s, int l, const int& rows,
		const int& cols, vector<vector<bool>>&vis, const int &nowx,
		const int& nowy)
	{
		if (nowx<rows&&nowx >= 0 && nowy<cols&&nowy >= 0 && !vis[nowx][nowy] &&
			matrix[nowx*cols + nowy] == s[l])
			return true;
		return false;
	}
	bool search(char* matrix, const string &s, int l, const int& rows,
		const int& cols, vector<vector<bool>>&vis, const int &nowx,
		const int& nowy)
	{
		if (l == s.length())
			return true;

		for (int i = 0; i<4; i++)
		{
			int nextx = nowx + dir[i][0];
			int nexty = nowy + dir[i][1];
			if (chech(matrix, s, l, rows, cols, vis, nextx, nexty))
			{
				vis[nextx][nexty] = 1;
				if (search(matrix, s, l + 1, rows, cols, vis, nextx, nexty))
					return true;
				vis[nextx][nexty] = 0;
			}
		}
		return false;
	}
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (str == nullptr)
			return true;
		if (matrix == nullptr || rows < 1 || cols < 1) // ¼ÇµÃÅÐ¶Ï£¡
			return false;
		string s;
		s = str;
		for (int i = 0; i<rows; i++)
		{
			for (int j = 0; j<cols; j++)
			{
				if (matrix[i*cols + j] == s[0])
				{
					vector<vector<bool>>vis(rows, vector<bool>(cols));
					vis[i][j] = 1;
					if (search(matrix, s, 1, rows, cols, vis, i, j))
						return true;
					vis[i][j] = 0;
				}
			}
		}
		return false;
	}


};

int main()
{
	char matrix[13] = "ABCESFCSADEE";
	char str[7] = "ABCCED";
	Solution s;
	bool res = s.hasPath(matrix, 3, 4, str);
	return 0;
}