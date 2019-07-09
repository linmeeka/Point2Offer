#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
	// 新数组
	void replaceSpace(char *str, int length) {
		string res = "";
		for (int i = 0; i<length; i++)
		{
			char c = str[i];
			if (c == ' ')
			{
				res += "\%";
				res += "20";
			}
			else
				res += c;
		}
		auto ret = res.c_str();
		strcpy(str, ret);
	}
	// 原数组
	void replaceSpace2(char *str, int length) {
		int cnt = 0;
		for (int i = 0; i<length; i++)
			if (str[i] == ' ')
				cnt++;
		int l = length + cnt * 2;
		l--;
		for (int i = length - 1; i >= 0; i--)
		{
			if (str[i] == ' ')
			{
				str[l] = '0';
				l--;
				str[l] = '2';
				l--;
				str[l] = '/%';
				l--;
			}
			else
			{
				str[l] = str[i];
				l--;
			}
		}
	}
};


int main()
{
	Solution s;
	char str[13] = "we are happy";
	s.replaceSpace(str, 13);
	return 0;
}