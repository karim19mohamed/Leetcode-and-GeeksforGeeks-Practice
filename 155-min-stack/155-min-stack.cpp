class MinStack {
    stack<pair<int,int>> st;
    int min_val;
public:
    MinStack() {
        min_val = INT_MAX;
    }
    
    void push(int val) {
        min_val = min(min_val, val);
        st.push({val, min_val});
    }
    
    void pop() {
        st.pop();
        min_val = (!st.empty())? st.top().second : INT_MAX;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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