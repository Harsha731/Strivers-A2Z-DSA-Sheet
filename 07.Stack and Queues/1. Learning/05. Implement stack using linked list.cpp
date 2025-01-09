/*
Question:
You have a linked list and you have to implement the functionalities push and pop of stack using this given linked list. Your task is to use the class as shown in the comments in the code editor and complete the functions push() and pop() to implement a stack.

Approach:
- We use the class `MyStack` to represent the stack implemented using a linked list.
- The stack is implemented using a singly linked list where each node represents an element in the stack.
- The `push(int)` function inserts an element at the top of the stack by creating a new node and updating the `next` pointer to point to the current top.
- The `pop()` function removes the top element from the stack by updating the `top` pointer to the next node and returning the data of the removed node.

Code:
*/

class MyStack {
  private:
    StackNode *top;
  public:
    void push(int x) {   
            StackNode* newNode = new StackNode(x); // creating the node
            newNode -> next = top;
            top = newNode;
    }
    int pop() {
        
        if(top == nullptr)  {
            return -1;
        } else  {
            StackNode* currNode = top;
            top = top->next;
            int elem = currNode->data;
            delete currNode;
            return elem;
        }
    }
    MyStack() { top = NULL; }
};

/*
Complexity Analysis:
- The `push()` operation has a time complexity of O(1) since we only need to create a new node and update the `top` pointer.
- The `pop()` operation has a time complexity of O(1) since we only need to update the `top` pointer and delete the node.
- The space complexity is O(N), where N is the total number of elements stored in the stack (linked list).
*/

