Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).


public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (!s2.empty()){
            while(!s2.empty()){
                int tmp = s2.top();
                s2.pop();
                s1.push(tmp);
            }
        }
        s2.push(x);
        while(!s1.empty()){
            int tmp = s1.top();
            s1.pop();
            s2.push(tmp);
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int tmp = s2.top();
        s2.pop();
        return tmp;
    }
    
    /** Get the front element. */
    int peek() {
        return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s2.empty();
    }
private:
    stack<int>s1;
    stack<int>s2;
