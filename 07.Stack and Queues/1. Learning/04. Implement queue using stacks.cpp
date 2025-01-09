/*
Question:
Implement a Queue using two stacks s1 and s2.

Approach:
- We use the class `Queue` to represent the queue.
- The queue is implemented using two stacks `input` and `output`.
- The `enqueue(int)` function inserts an element into `input` stack.
- The `dequeue()` function transfers elements from `input` stack to `output` stack if `output` is empty, and returns the top element from `output` stack as the dequeued element.
- To transfer elements from `input` to `output`, we pop each element from the top of `input` and push it into `output`.
- After transferring elements, we pop the top element from `output` as the dequeued element.

Code:
*/
/*
input Stack: Used to store elements as they are pushed.
output Stack: Used to reverse the order of elements from input to simulate queue behavior (FIFO).
We reverse the elements and keep in output stack, such that the first element inserted will now be at top in the stack
So, when ever the output stack becomes empty, we insert all the elements in left stack to right stack
*/
class MyQueue {
public:
    stack<int> input, output;
    MyQueue() {}
    
    void push(int x) {
        input.push(x);
    }

    int pop(void) {
        int t = peek();
        output.pop();
        return t;
    }

    // Get the front element.
    int peek(void) {
        if (output.empty())
            while (input.size())
                output.push(input.top()), input.pop();
        return output.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return input.empty() && output.empty();
    }
};

_________________________________________________

// Using 1 stack and recursion
class Queue {
public:
    stack<int> s;
    
    // Push element x to the back of queue.
    void push(int x) {
        pushHelper(x);
    }
    void pushHelper(int x){
        if(s.size()==0){
            s.push(x);
            return;
        }
        int data;
        data = s.top();
        s.pop();
        pushHelper(x);
        s.push(data);
        return;
        
    }

    // Removes the element from in front of queue.
    void pop(void) {
        s.pop();
    }

    // Get the front element.
    int peek(void) {
        return s.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return (s.size()==0);
    }
};
