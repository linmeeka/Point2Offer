
/*
ʱ��o(n)���ռ�o(1)
˼·���������Ԫ��λ�ã����±�Ϊi��Ԫ�ؽ������±�Ϊn[i]��λ�ã�������n[i]=n[n[i]]��
˵�����ظ���ÿ��ѭ����n[i]=iֹͣ����ʱ˵���Ѿ�����ȷλ��
*/
class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		for (int i = 0; i<length; i++)
		{
			int t = numbers[i];
			if (t>length - 1 || t<0)
				return false;
		}
		for (int i = 0; i<length; i++)
		{
			while (numbers[i] != i)
			{
				if (numbers[i] == numbers[numbers[i]])
				{
					*duplication = numbers[i];
					return true;
				}
				int t = numbers[i];
				numbers[i] = numbers[numbers[i]];
				numbers[t] = t;
			}
		}
		return false;

	}
};


/*
leetcode 287.
���ı�ԭ�����ֵ�������Ӷ���ռ�
ʱ�䣺O(nlogn),�ռ�O(1)
˼·����һ����Χ[l,r]�������ظ������������Χ�ڵ�Ԫ��������r-1+1
ʹ�ö��֣�������һ��Χ
*/
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int l = 1;
		int r = nums.size() - 1;
		int res = 0;
		while (l<r)
		{
			int mid = (l + r) / 2;
			int cntl = count(nums, l, mid);
			int cntr = count(nums, mid + 1, r);
			if (cntl>mid - l + 1)
				r = mid;
			else if (cntr>r - mid)
				l = mid + 1;
		}
		return l;
	}
	int count(const vector<int>& nums, int l, int r)
	{
		int cnt = 0;
		for (auto num : nums)
		{
			if (num >= l&&num <= r)
				cnt++;
		}
		return cnt;
	}
};