class Solution {
public:
	void reOrderArray(vector<int> &array) {

		int num = 0;
		for (int a : array)
		{
			if (a % 2)
				num++;
		}
        int s=0;
		while (1)
		{
			bool flag = false;
			int t = 0;
			bool b = false;
			for (int i = s; i<array.size(); i++)
			{
				if (array[i] % 2 == 0)
				{
					if (!flag&&t == num)
					{
                        s=i;
						b = true;
						break;
					}
					else
						flag = true;
					int j;
					for (j = i + 1; j<array.size(); j++)
					{
						if (array[j] % 2)
						{
							t++;
							swap(array[j-1], array[j]);
						}
						else
							break;
					}
					i = j-1;
				}
				else
					t++;
			}
			if (b||(!flag&&t == num))
				break;
		}
	}
};