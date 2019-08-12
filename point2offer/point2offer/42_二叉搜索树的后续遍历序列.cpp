class Solution {
public:
	bool check(vector<int> s, int l, int r)
	{
		if (l >= r)
			return true;
		int t = s[r];
		int tmp = l;
		if (s[l]>t)
		{
			for (int i = l; i<r; i++)
			{
				if (s[i] <= t)    return false;
			}
			return check(s, l, r - 1);
		}
		else if (s[r - 1]<t)
		{
			for (int i = l; i<r; i++)
			{
				if (s[i] >= t)    return false;
			}
			return check(s, l, r - 1);
		}
		for (int i = l; i<r - 1; i++)
		{
			if (s[i]<t&&s[i + 1]>t)
			{
				for (int j = l; j <= i; j++)
				{
					if (s[j] >= t)    return false;
				}
				for (int j = i + 1; j<r; j++)
				{
					if (s[j] <= t)    return false;
				}
				return check(s, l, i) && check(s, i + 1, r - 1);
			}
		}
		return true;
	}
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() == 0)
			return false;
		return check(sequence, 0, sequence.size() - 1);
	}
};