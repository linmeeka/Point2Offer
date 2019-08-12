#include<algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int m, n;
	cin >> n >> m;
	if (n == 0)	return 0;
	vector<int> tmp;
	vector<vector<int>> v(n,tmp);
	for (int i = 0; i < m; i++)
	{
		int t;
		cin >> t;
		v[t-1].push_back(1);
	}
	int res = v[0].size();

	for (int i = 0; i < n; i++)
	{
		if(res>v[i].size())
		res = v[i].size();
	}
	cout << res << endl;
	return 0;
}