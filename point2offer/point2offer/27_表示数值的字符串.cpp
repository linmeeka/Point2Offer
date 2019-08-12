#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
	bool isNum(string str, int i)
	{
		int l = str.length();
		if (i >= l || i<0)
			return false;
		if (str[i] >= '0'&&str[i]<='9')
			return true;
		return false;
	}
	bool isNumeric(string strin)
	{
		bool flage = false;
		bool flagf = false;
		bool flagp = false;
		std::string str = strin;
		int l = str.length();
		for (int i = 0; i<l; i++)
		{
			if (!isNum(str, i))
			{
				if (i == l - 1)
					return false;
			}
			if ((str[i] == '-' || str[i] == '+'))
			{
				if (i == 0 || (str[i - 1] == 'E' || str[i - 1] == 'e'))
				{
					if (isNum(str, i + 1) || (!flagp&&str[i + 1] == '.'))
					{
						flagf = true;
						continue;
					}
					else
						return false;
				}
				else
					return false;
			}
			else if (!flage && (str[i] == 'E' || str[i] == 'e'))
			{
				flage = true;
				continue;
			}
			else if (str[i] == '.')
			{
				if (i == l - 1)
					return false;
				if (!flage&&!flagp && (isNum(str, i + 1) && (i == 0 || isNum(str, i - 1) || str[i - 1] == '+' || str[i - 1] == '-')))
				{
					flagp = true;
					continue;
				}
				else
					return false;
			}
			else if (isNum(str, i))
				continue;
			else
				return false;
		}
		return true;
	}
	 bool scanNum(const char **str)
    {
        if(**str=='+'||**str=='-')
           ++(*str);
        return scanUnsignNum(str);
    }
    bool scanUnsignNum(const char **str)
    {
       const char* before = *str;
	while (**str != '\0' && **str >= '0' && **str <= '9')
		++(*str);

	// 当str中存在若干0-9的数字时，返回true
	return *str > before;
    }
    bool isNumeric(const char* str)
   	{
        if(str==NULL)
            return false;
        bool isNum=scanNum(&str);
        if(*str=='.')
        {
            ++str;
            isNum=scanUnsignNum(&str)||isNum;
        }
        if(*str=='e'||*str=='E')
        {
            ++str;
            isNum=isNum&&scanNum(&str);
        }
        return isNum&&*str=='\0';
	}
};

int main()
{
	string s = "1.79769313486232E+308";
	Solution so;
	auto res=so.isNumeric(s);
	return 0;
}


