class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        pq.push(1);
        
        int count = 0;
        while(true){
            count++;
            if(count == n)
                break;
                
            int minUgly = pq.top();
            while(!pq.empty() && pq.top() == minUgly) pq.pop();
            
            if(minUgly < INT_MAX / 2)
                pq.push(minUgly * 2);
            if(minUgly < INT_MAX / 3)
                pq.push(minUgly * 3);
            if(minUgly < INT_MAX / 5)
                pq.push(minUgly * 5);
        }
        return pq.top();
    }
};