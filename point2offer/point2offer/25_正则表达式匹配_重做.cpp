class Solution {
public:
	bool find(char* str, char* pattern)
	{
		if (*str == '\0'&&*pattern == '\0')
			return true;
		if (*str != '\0'&&*pattern == '\0')
			return false;
		if (*(pattern + 1) == '*')
		{
			if (*pattern == '.'&&*str != '\0' || *pattern == *str)
				return (find(str, pattern + 2) || find(str + 1, pattern + 2) || find(str + 1, pattern));
			else
				return find(str, pattern + 2);

		}
		if (*pattern == '.'&&*str != '\0' || *pattern == *str)
			return find(str + 1, pattern + 1);
		return false;

	}

	bool match(char* str, char* pattern)
	{
		if (str == NULL || pattern == NULL)
			return false;
		return find(str, pattern);
	}
};