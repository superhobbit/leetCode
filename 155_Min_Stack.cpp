Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

stack is much faster:
public:
    /** initialize your data structure here. */
    MinStack(){
       
    }
    
    void push(int x) {
        s.push(x);
        if(minimum.empty() || x<=minimum.top()) minimum.push(x);
    }
    
    void pop() {
        if (s.top() == minimum.top()) {
            s.pop();
            minimum.pop();
        }else s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minimum.top();
    }

private:
    stack<int> s;
    stack<int> minimum;
    
    
I used vector at first:

    MinStack():minimum(INT_MAX) {
       
    }
    
    void push(int x) {
        s.push(x);
        if (x <= minimum) store.push_back(minimum);
        minimum = min(minimum,x);   
    }
    
    void pop() {
        if (s.top() == minimum) {
            minimum = store.back();
            store.erase(store.end()-1, store.end());
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        if (!s.empty()) return minimum;
        return NULL;
    }

private:
    stack<int> s;
    vector<int> store;
    int minimum;
