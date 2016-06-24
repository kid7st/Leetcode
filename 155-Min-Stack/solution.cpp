class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        items.push_back(x);
        if(minIndexs.empty()){
            minIndexs.push_back(0);
        }else if(items[minIndexs.back()] > x){
            minIndexs.push_back(items.size() - 1);
        }
    }
    
    void pop() {
        items.pop_back();
        if(minIndexs.back() == items.size()){
            minIndexs.pop_back();
        }
    }
    
    int top() {
        return items[items.size() - 1];
    }
    
    int getMin() {
        return items[minIndexs.back()];
    }

private:
    vector<int> items;
    vector<int> minIndexs;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */