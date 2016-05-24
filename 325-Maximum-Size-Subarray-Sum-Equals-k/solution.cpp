class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> index;
        index[0] = 0;
        int sum = 0;
        
        int max = 0;
        for(int i = 1; i <= nums.size(); i++){
            sum = sum + nums[i - 1];
            if(index.find(sum - k) != index.end()){
                if(abs(i - index[sum - k]) > max){
                    max = i - index[sum - k];
                }
            }
            
            if(index.find(sum) == index.end())
                index[sum] = i;
        }
        
        return max;
    }
};