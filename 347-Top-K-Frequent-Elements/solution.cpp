class Cmper{
public:
    bool operator () (const pair<int, int>& left, const pair<int, int>& right){
        return left.second > right.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int num : nums){
            count[num] += 1;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmper> heap;
        
        for(auto c : count){
            int value = c.first;
            int freq = c.second;
            if(heap.size() < k){
                heap.push(pair<int, int>(value, freq));
            }else if(heap.top().second < freq){
                heap.pop();
                heap.push(pair<int, int>(value, freq));
            }       
        }
        
        vector<int> res;
        while(!heap.empty()){
            res.push_back(heap.top().first);
            heap.pop();
        }
        
        return res;
        
    }
};