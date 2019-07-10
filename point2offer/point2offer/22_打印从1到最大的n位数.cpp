#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
void print(string s)
{
	cout << s << endl;
}
void add(string & num, int &count)
{
	int in = 1;
	for (int i = num.length() - 1; i >= 0; i--)
	{
		int t = num[i] - '0' +in;
		in = t / 10;
		t %= 10;
		num[i] = t + '0';
	}
	if (in)
	{
		num = "1" + num;
		count++;
	}
}
int main()
{
	string num="";
	int mmax = 3;
	int count = 0;
	while (count <= 3)
	{
		print(num);
		add(num,count);
	}
	return 0;
}