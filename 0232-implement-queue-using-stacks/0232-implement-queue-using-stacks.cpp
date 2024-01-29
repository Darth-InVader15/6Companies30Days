class MyQueue {
public:
    stack<int> stk1, stk2;
    MyQueue() {
        // boomin'
    }
    
    void push(int x) {
        stk1.push(x);
    }
    
    int pop() {
        while(stk1.size() != 1)
        {
            stk2.push(stk1.top());
            stk1.pop();
        }
        auto ele = stk1.top();
        stk1.pop();
        
        while(!stk2.empty())
        {
            stk1.push(stk2.top());
            stk2.pop();
        }
        return ele;
    }
    
    int peek() {
        while(!stk1.size() == 0)
        {
            stk2.push(stk1.top());
            stk1.pop();
        }
        auto ele = stk2.top();
        while(!stk2.empty())
        {
            stk1.push(stk2.top());
            stk2.pop();
        }
        return ele;        
    }
    
    bool empty() {
        return stk1.empty();
        
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