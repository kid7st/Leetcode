class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        while(!main.empty()){
            second.push(main.top());
            main.pop();
        } 
        main.push(x);
        while(!second.empty()){
            main.push(second.top());
            second.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        main.pop();    
    }

    // Get the front element.
    int peek(void) {
        return main.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return main.empty();    
    }
    
private:
    stack<int> main;
    stack<int> second;
};