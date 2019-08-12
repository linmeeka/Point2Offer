#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, k;
		cin >> n >> k;
		n *= 2;
		vector<long long int> v(201,0);
		for (int i = 0; i < n; i++)
		{
			cin>>v[i];
		}
		while (k--)
		{
			vector < long long int>tmp(201, 0);
			
			int cnt = n-1;
			for (int i = n - 1,j=n/2-1; j >= 0; i--,j--)
			{
				tmp[cnt--] = v[i];
				tmp[cnt--] = v[j];
			}
			v = tmp;
		}
		for (int i = 0; i < n; i++)
		{
			cout << v[i];
			if (i == n - 1)
				cout << endl;
			else
				cout << " ";
		}
	}
	return 0;
}