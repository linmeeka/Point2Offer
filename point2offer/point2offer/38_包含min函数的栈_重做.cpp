/*
思路：用一个辅助栈，存放到当前为止的最小元素
因为原栈的pop是有顺序的，所以最小元素的删除和更新也是有序的
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