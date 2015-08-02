class Stack {
public:
    // Push element x onto stack.
    queue<int> q;
    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i ++) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};