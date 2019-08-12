#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<int>v;
		vector<int>res(n,0);
		vector<bool> flag(n, false);
		for (int i = 1; i <= n; i++)
			v.push_back(i);
		int cnt = 0;
		int num = 0;
		//int flag = 0;
		for (int i = 0; i < n; i++)
		{
			while (1)
			{
				cnt %= n;
				if (flag[cnt] == false)
					break;
				cnt++;
			}
			cnt++;
			while (1)
			{
				cnt %= n;
				if (flag[cnt] == false)
				{
					res[cnt] = v[i];
					flag[cnt] = true;
					break;
				}
				cnt++;
			}
		}
		for (int i = 0; i < n; i++)
		{
			cout << res[i];
			if (i == n - 1)	cout << endl;
			else
			{
				cout << " ";
			}
		}
	}
	return 0;
}