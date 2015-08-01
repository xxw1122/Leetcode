class Queue {
public:
    stack<int> stk1;
    stack<int> stk2;
    // Push element x to the back of queue.
    void push(int x) {
        stk1.push(x);
    }
    // move the element in stk1 to stk2;
    void helper() {
        while (!stk1.empty()) {
            stk2.push(stk1.top());
            stk1.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (stk2.empty()) {        
            helper();
        }
        stk2.pop();
    }

    // Get the front element.
    int peek(void) {
        if (stk2.empty()) {
            helper();
        }
        return stk2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stk1.empty() && stk2.empty();
    }
};