class MyQueue {
public:
    stack<int> st,mn;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        while(!st.empty())
        {
            mn.push(st.top());
            st.pop();
        }
        int ans = mn.top();
        mn.pop();
        while(!mn.empty())
        {
            st.push(mn.top());
            mn.pop();
        }
        return ans; 
    }
    
    int peek() {
       while(!st.empty())
        {
            mn.push(st.top());
            st.pop();
        }
        int ans = mn.top();
        
        while(!mn.empty())
        {
            st.push(mn.top());
            mn.pop();
        }
        return ans;
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
