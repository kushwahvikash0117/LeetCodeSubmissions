class MyQueue {
    stack<int> s1, s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int x;
        if(!s2.empty()){
            x = s2.top();
            s2.pop();
            return x;
        }
        else{
            while(!s1.empty()){
                x = s1.top();
                s1.pop();
                s2.push(x);
            }
            x = s2.top();
            s2.pop();
            return x;
        }
    }
    
    int peek() {
        if(!s2.empty()) return s2.top();
        else{
            while(!s1.empty()){
                int x = s1.top();
                s1.pop();
                s2.push(x);
            }
            return s2.top();
        }
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
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