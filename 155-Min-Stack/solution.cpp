class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        minIndex = 0;
    }
    
    void push(int x) {
        items.push_back(x);
        if(items[minIndex] > x){
            minIndex = items.size() - 1;
        }
    }
    
    void pop() {
        items.pop_back();
        if(minIndex == items.size()){
            minIndex = 0;
            for(int i = 0; i < items.size(); i++){
                if(items[minIndex] > items[i]){
                    minIndex = i;
                }
            }
        }
    }
    
    int top() {
        return items[items.size() - 1];
    }
    
    int getMin() {
        return items[minIndex];
    }

private:
    vector<int> items;
    int minIndex;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */