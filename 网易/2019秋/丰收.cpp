#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n,m;
	cin >> n;
	vector<int> a;
	int tmp = 0;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		a.push_back(t+tmp);
		tmp += t;
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int q;
		cin >> q;
		int l = 0;
		int r = n - 1;
		int res = 0;
		while (l<=r)
		{
			int mid = (l + r) / 2;
			if(mid==0&&q<=a[mid])
			{
				res = mid + 1;
				break;
			}
			if (q <= a[mid] && q>a[mid - 1])
			{
				res = mid + 1;
				break;
			}
			else if (q > a[mid])
				l = mid + 1;
			else if (q <= a[mid - 1])
				r = mid - 1;
		}
		cout << res << endl;
	}
	return 0;
}