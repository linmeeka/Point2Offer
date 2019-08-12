/*
˼·����һ������ջ����ŵ���ǰΪֹ����СԪ��
��Ϊԭջ��pop����˳��ģ�������СԪ�ص�ɾ���͸���Ҳ�������
*/
class Solution {
public:
	stack<int> s1, s2;
	void push(int value) {
		s1.push(value);
		if (s2.empty() || s2.top()>value)
			s2.push(value);
		else
			s2.push(s2.top());
	}
	void pop() {
		s1.pop();
		s2.pop();
	}
	int top() {
		return s1.top();
	}
	int min() {
		return s2.top();
	}
};