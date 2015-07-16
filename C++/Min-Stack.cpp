class MinStack {
private:
	stack<int> stk1, stk2;
public:
    void push(int x) {
        stk1.push(x);
        if (stk2.empty()) {
        	stk2.push(x);
        } else {
        	if (x >= stk2.top()) {
        		stk2.push(stk2.top());
        	} else {
        		stk2.push(x);
        	}
        }
    }

    void pop() {
        stk1.pop();
        stk2.pop();
    }

    int top() {
        return stk1.top();
    }

    int getMin() {
        return stk2.top();
    }
};