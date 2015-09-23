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
        queueArr[currentQueue].push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(queueArr[currentQueue].empty()){
            currentQueue = (currentQueue + 1)%2;
        }
        while(queueArr[currentQueue].size()!=1){
            queueArr[(currentQueue + 1)%2].push(queueArr[currentQueue].front());
            queueArr[currentQueue].pop();
        }
        queueArr[currentQueue].pop();
    }

    // Get the top element.
    int top() {
        if(queueArr[currentQueue].empty()){
            currentQueue = (currentQueue + 1)%2;
        }
        while(queueArr[currentQueue].size()!=1){
            queueArr[(currentQueue + 1)%2].push(queueArr[currentQueue].front());
            queueArr[currentQueue].pop();
        }
        return queueArr[currentQueue].front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return queueArr[0].empty() && queueArr[1].empty();
    }
    
    Stack(){
        currentQueue = 0;
    }
    
private:
    queue<int> queueArr[2];
    int currentQueue;
};
