class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}

		int res = stack2.top();
		stack2.pop();
		while (!stack2.empty())
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
		return res;
	}
	/*
		把stack2 的pop完再装入下一波
		因为是先进先出，每次pop，stack1里有剩余元素是不影响的
	*/
	int pop2() {
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		int res = stack2.top();
		stack2.pop();
		return res;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};


/*
leetcode 225
用队列模拟栈
*/
class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		q1.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {

		while (q1.size()>1)
		{
			q2.push(q1.front());
			q1.pop();
		}
		int res = q1.front();
		q1.pop();
		while (!q2.empty())
		{
			q1.push(q2.front());
			q2.pop();
		}
		return res;
	}

	/** Get the top element. */
	int top() {
		// return q1.peek();

		while (q1.size()>1)
		{
			q2.push(q1.front());
			q1.pop();
		}
		int res = q1.front();
		q1.pop();
		q2.push(res);
		while (!q2.empty())
		{
			q1.push(q2.front());
			q2.pop();
		}
		return res;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q1.empty();
	}
private:
	queue<int> q1;
	queue<int> q2;
};

/**
* Your MyStack object will be instantiated and called as such:
* MyStack* obj = new MyStack();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->top();
* bool param_4 = obj->empty();
*/