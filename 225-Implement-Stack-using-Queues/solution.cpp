class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        main.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int size = main.size();
        for(int i = 0; i < size - 1; i++){
            main.push(main.front());
            main.pop();
        }
        main.pop();
    }

    // Get the top element.
    int top() {
        int size = main.size();
        for(int i = 0; i < size - 1; i++){
            main.push(main.front());
            main.pop();
        }
        int res = main.front();
        main.push(main.front());
        main.pop();
        return res;
    }

    // Return whether the stack is empty.
    bool empty() {
        return main.empty();   
    }

private:
    queue<int> main;
};