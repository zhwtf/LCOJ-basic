class Queue {
public:
    stack<int> stc;
    // Push element x to the back of queue.
    void push(int x) {
        pushHelper(x);
    }
    void pushHelper(int x){
        if(stc.size()==0){
            stc.push(x);
            return;
        }
        int data;
        data = stc.top();
        stc.pop();
        pushHelper(x);
        stc.push(data);
        return;

    }

    // Removes the element from in front of queue.
    void pop(void) {
        stc.pop();
    }

    // Get the front element.
    int peek(void) {
        return stc.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stc.empty();
    }
};
