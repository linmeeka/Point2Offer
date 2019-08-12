/*
用set
O（nlogk)
*/

class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		multiset <int, greater<int>> s;
		multiset <int, greater<int>>::iterator it;
		vector<int> res;
		int l = num.size();
		if (size <= 0 || size>l)    return res;
		for (int i = 0; i<size; i++)
		{
			s.insert(num[i]);
		}
		it = s.begin();
		res.push_back(*it);
		for (int i = size; i<l; i++)
		{
			s.erase(num[i - size]);
			s.insert(num[i]);
			it = s.begin();
			res.push_back(*it);
		}
		return res;
	}
};

/*
deque
O（n)

每次从后把小于当前的数都pop掉，保证队列里的数是降序的！
*/

class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> res;
		int l = num.size();
		if (size <= 0 || size>l)    return res;

		deque<int> q;
		for (int i = 0; i<l; i++)
		{
			while (q.size() && num[q.back()] <= num[i])    q.pop_back();
			while (q.size() && i - q.front() + 1>size)    q.pop_front();
			q.push_back(i);
			if (i >= size - 1)
			{
				res.push_back(num[q.front()]);
			}
		}
		return res;
	}
};