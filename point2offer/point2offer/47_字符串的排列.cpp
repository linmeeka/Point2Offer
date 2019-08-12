class Solution {
public:
	void dfs(vector<string>& res, string &now, const string &str,
		vector<bool> &flag)
	{
		if (now.length() == str.length())
		{
			res.push_back(now);
			return;
		}
		for (int i = 0; i<str.length(); i++)
		{
			if (!flag[i])
			{
				flag[i] = true;
				now += str[i];
				dfs(res, now, str, flag);
				flag[i] = false;
				now = now.substr(0, now.length() - 1);
			}
		}
		return;
	}
	vector<string> Permutation(string str) {
		vector<string> res;
		string now = "";
		int l = str.length();
		if (l == 0)    return res;
		vector<bool> flag(l, false);
		dfs(res, now, str, flag);
		sort(res.begin(), res.end());
		res.erase(unique(res.begin(), res.end()), res.end());
		return res;
	}
};

class Solution {
public:
	void find(vector<string> &res, string str, int s)
	{
		if (s >= str.length())    return;
		for (int i = s; i<str.length(); i++)
		{
			for (int j = i + 1; j<str.length(); j++)
			{
				if (str[i] != str[j])
				{
					string now = str;
					char c = str[i];
					now[i] = now[j];
					now[j] = c;
					res.push_back(now);
					find(res, now, s + 1);
				}
			}
		}
	}
	vector<string> Permutation(string str) {
		vector<string> res;
		if (str.length() == 0)    return res;
		res.push_back(str);
		find(res, str, 0);
		sort(res.begin(), res.end());
		res.erase(unique(res.begin(), res.end()), res.end());
		return res;
	}
};