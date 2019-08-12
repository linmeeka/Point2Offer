class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		stack<int> s;
		int i = 0;
		int j = 0;
		while (i<pushV.size())
		{
			s.push(pushV[i]);
			i++;
			while (!s.empty() && popV[j] == s.top())
			{
				j++;
				s.pop();
			}
		}
		if (s.empty())
			return true;
		else
			return false;
	}
};