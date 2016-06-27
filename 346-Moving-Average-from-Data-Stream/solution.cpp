class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
        sum = 0;
    }
    
    double next(int val) {
        if(movingQueue.size() >= size){
            sum -= movingQueue.front();
            movingQueue.pop();
        }
        movingQueue.push(val);
        sum += val;
        return double(sum) / double(movingQueue.size());
    }

private:
    queue<int> movingQueue;
    int sum;
    int size;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */