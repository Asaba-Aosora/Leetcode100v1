class MinStack {
    stack<int> stk;
    stack<int> min_stk;     // 注意，这里不需要按顺序存本来的值，只需要存 "x为栈顶时，对应的最小值"
public:
    MinStack() {}
    
    void push(int val) {
        int cur_min = min_stk.empty() ? val : min(val, min_stk.top());
        min_stk.push(cur_min);
        stk.push(val);
    }
    
    void pop() {
        stk.pop();
        min_stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */