#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> a,t;
	for (int i = 0; i < n; i++)
	{
		int ai;
		cin >> ai;
		a.push_back(ai);
	}
	for (int i = 0; i < n; i++)
	{
		int ti;
		cin >> ti;
		t.push_back(ti);
	}
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (t[i] == 1)	res += a[i];
	}
	int now = res;
	for (int i = 0; i < n; i++)
	{
		if (t[i] == 0)
		{
			int tmp = 0;
			for (int j = i; j < k+i&&j < n; j++)
			{
				if (t[j] == 0)
					tmp += a[j];
			}
			now = max(now, res + tmp);
			if (i + k >= n) break;
		}
		
	}
	cout << now << endl;
	return 0;
}