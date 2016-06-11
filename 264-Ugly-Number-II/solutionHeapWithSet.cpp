class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_set<int> hash;
        pq.push(1);
        hash.insert(1);
        
        int count = 0;
        while(true){
            count++;
            if(count == n)
                break;
                
            int minUgly = pq.top();
            pq.pop();
            
            if(minUgly < INT_MAX / 2 && hash.find(minUgly*2) == hash.end()){
                pq.push(minUgly*2);
                hash.insert(minUgly*2);
            }
            
            if(minUgly < INT_MAX / 3 && hash.find(minUgly*3) == hash.end()){
                pq.push(minUgly*3);
                hash.insert(minUgly*3);
            }
            
            if(minUgly < INT_MAX / 5 && hash.find(minUgly*5) == hash.end()){
                pq.push(minUgly*5);
                hash.insert(minUgly*5);
            }
        }
        return pq.top();
    }
};