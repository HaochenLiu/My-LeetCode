/*
225. Implement Stack using Queues

Implement the following operations of a stack using queues.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
Update (2015-06-11):
The class name of the Java function had been updated to MyStack instead of Stack.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and all test cases.
*/

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        queueArr[cur].push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(queueArr[cur].empty()){
            cur = 1 - cur;
        }
        while(queueArr[cur].size() != 1){
            queueArr[1 - cur].push(queueArr[cur].front());
            queueArr[cur].pop();
        }
        queueArr[cur].pop();
    }

    // Get the top element.
    int top() {
        if(queueArr[cur].empty()){
            cur = 1 - cur;
        }
        while(queueArr[cur].size() != 1){
            queueArr[1 - cur].push(queueArr[cur].front());
            queueArr[cur].pop();
        }
        return queueArr[cur].front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return queueArr[0].empty() && queueArr[1].empty();
    }
    
    Stack(){
        cur = 0;
    }
    
private:
    queue<int> queueArr[2];
    int cur;
};
