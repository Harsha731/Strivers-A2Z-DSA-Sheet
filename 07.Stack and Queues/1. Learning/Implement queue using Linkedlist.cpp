Push : If no Node, then f = r = newNode
Else, rear->next = newNode and update the rear node
Pop : If no node, return -1
Else, store the front node value, update f, delete f node, return data

void MyQueue::push(int x) {

    QueueNode *newNode = new QueueNode(x);
    if (front == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int MyQueue::pop() {

    if (front == nullptr) {
        return -1;
    }

    QueueNode *temp = front;
    front = front->next;
    int data = temp->data;
    delete temp;
    return data;
}

