/*
232. Implement Queue using Stacks

Implement the following operations of a queue using stacks.
push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        stacks[0].push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(stacks[1].empty()){
            while(!stacks[0].empty()){
                stacks[1].push(stacks[0].top());
                stacks[0].pop();
            }
        }
        stacks[1].pop();
    }

    // Get the front element.
    int peek(void) {
        if(stacks[1].empty()){
            while(!stacks[0].empty()){
                stacks[1].push(stacks[0].top());
                stacks[0].pop();
            }
        }
        return stacks[1].top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stacks[0].empty() && stacks[1].empty();
    }
    
private:
    stack<int> stacks[2];
};
