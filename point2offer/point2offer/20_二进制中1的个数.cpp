/*
˼·��λ����
flag����checkÿһλ�Ƿ���1
ע�⣺ ����Ϊ�������ڣ�ʹ��λ���㣬��Ҫ��/2 ��
ʱ�临�Ӷȣ� intλ����
*/
class Solution {
public:
	int  NumberOf1(int n) {
		int res = 0;
		int flag = 1;
		while (flag)
		{
			if (n&flag)
				res++;
			flag <<= 1;
		}
		return res;
	}
};

/*
˼·: һ��������һ���൱�ڰ�������������ҵ�1��ʼȡ������һ���ٺ�ԭ�������㣬�൱�ڰ����ҵ�1���0
���ÿ����ô����һ�£�������һ��1
ʱ�临�Ӷ�: 1�ĸ�����	
*/
class Solution {
public:
	int  NumberOf1(int n) {
		int res = 0;
		while (n)
		{
			n = n&(n - 1);
			res++;
		}
		return res;
	}
};