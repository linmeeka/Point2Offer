#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void get(vector<vector<int>> &t,vector<int>&now,const vector<int> &ori,vector<bool>& f)
{
	if (now.size() == ori.size())
	{
		t.push_back(now);
		return;
	}
	for (int i = 0; i < ori.size(); i++)
	{
		if (!f[i])
		{
			now.push_back(ori[i]);
			f[i] = true;
			get(t, now, ori, f);
			f[i] = false;
			now.pop_back();
		}
	}
}
int main()
{
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	vector <int>res, tmp;
	vector<vector<int>> t;
	
	//tmp = v;
	//sort(tmp.begin(), tmp.end());
	//if(v[0]==)
	tmp = v;
	sort(tmp.begin(), tmp.end());
	vector<bool>
	get(t, tmp, v, f);
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			int tt = tmp[i];
		}
	}
	return 0;
}
