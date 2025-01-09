/*
Question:
Implement a Stack using one queue.

Approach:
- We use the class `QueueStack` to represent the stack.
- The stack is implemented using one queue `q`.
- One queue is needed
- push - we insert the element we needed to insert at the end and we reinsert all the elements in front of this current element at the back

Code:
*/

class MyStack {
public:
	queue<int> que;
    MyStack() { }
        
    void push(int x) {
        que.push(x);
        for(int i=0;i<que.size()-1;++i){
            que.push(que.front());
            que.pop();
        }
    }

    // Removes the element on top of the stack.
    int pop() {
        int topVal = que.front();
        que.pop();
        return topVal;
    }

    // Get the top element.
    int top() {
        return que.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return que.empty();
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

/*
Complexity Analysis:
- The `push()` operation has a time complexity of O(N)
- The `pop()` operation has a time complexity of O(1)
- The space complexity is O(N), where N is the total number of elements stored in the queue.
*/

