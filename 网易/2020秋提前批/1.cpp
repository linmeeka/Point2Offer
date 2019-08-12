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
		vector<long long> v(n,0);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		sort(v.begin(), v.end());
		bool flag = true;
		long long int a = v[n-1];
		long long int b = v[n - 2];
		long long int c = v[n - 3];
		if (a >= b + c)
		{
			flag = false;
		
		}
		for (int i = n - 1; i >= 4; i--)
		{
			if (a >= b + c)
			{
				flag = false;
				break;
			}
			b = a;
			a = v[i - 1];
			c = v[i - 4];
		}
	
		if (flag)	cout << "YES" << endl;
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
