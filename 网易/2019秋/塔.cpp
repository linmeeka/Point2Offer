#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool cmp(const pair<int, int>&a, const pair<int, int>&b)
{
	return a.first < b.first;
}
int main()
{
	int n, k;
	cin >> n >> k;

	vector<pair<int, int>>a;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		a.push_back(make_pair(t, i + 1));
	}

	vector<pair<int, int>> res;
	int s = 0;
	int m = 0;
	
	for (int i = 0; i < k; i++)
	{
		sort(a.begin(), a.end(), cmp);
		if (a[n - 1].first - a[0].first <= 1)
		{
			break;
		}

		a[n - 1].first--;
		a[0].first++;
		res.push_back(make_pair(a[n - 1].second, a[0].second));
		m++;
	}
	sort(a.begin(), a.end(), cmp);
	s = a[n - 1].first - a[0].first;
	cout << s << " " << m << endl;
	for (int i = 0; i < res.size(); i++)
		cout << res[i].first << " " << res[i].second << endl;
	return 0;
}