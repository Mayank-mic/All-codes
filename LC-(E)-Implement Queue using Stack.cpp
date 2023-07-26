// Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

// Implement the MyQueue class:

// void push(int x) Pushes element x to the back of the queue.
// int pop() Removes the element from the front of the queue and returns it.
// int peek() Returns the element at the front of the queue.
// boolean empty() Returns true if the queue is empty, false otherwise.
// Notes:

// You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
// Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.



class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        stack<int> s1;
        stack<int> s2;
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        int r =s2.top();
        s2.pop();

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }

        return r;


    }
    
    int peek() {


        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        int r =s2.top();

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }

        return r;
        
    }
    
    bool empty() {

        return s1.empty();
        
    }
};
