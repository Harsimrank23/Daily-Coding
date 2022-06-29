class MyStack {
public:
    queue<int>q1;
    // queue<int>q2;
    MyStack() {
        while (!q1.empty())
            q1.pop();
        // while (!q2.empty())
        //     q2.pop();
    }
    
    void push(int x) {
        q1.push(x);
        for(int i=0;i<q1.size()-1;i++)
        {
            q1.push(q1.front());
            q1.pop();
        }
    }
    
    int pop() {
//         while(q1.size()>1)
//         {
//             q2.push(q1.front());q1.pop();}
        
//         int ans=q1.front();
//         q1.pop();
        
//        while(!q2.empty())
//         {q1.push(q2.front());q2.pop();}
        
        int ans=q1.front();
        q1.pop();
        return ans;
        
    }
    
    int top() {
//         int ans;
//         while(!q1.empty())
//         {
//             ans=q1.front();
//             q2.push(q1.front());q1.pop();}
        
        
//        while(!q2.empty())
//         {q1.push(q2.front());q2.pop();}
        
//         return ans;
        return q1.front();
    }
    
    bool empty() {
        return q1.empty()?true:false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */