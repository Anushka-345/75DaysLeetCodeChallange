#include <stack>
#include <algorithm>

class MinStack {
private:
    std::stack<int> mainStack;
    std::stack<int> minStack;

public:
    MinStack() {
        // Constructor: stacks are initialized automatically
    }
    
    void push(int val) {
        mainStack.push(val);
        
        // Push to minStack if it's empty or val is <= current minimum
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        // If the value being removed is the current minimum, pop it from minStack too
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};