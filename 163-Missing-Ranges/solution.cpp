class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        if(nums.size() == 0){
            if(lower == upper){
                res.push_back(to_string(upper));
            }else if(lower < upper){
                res.push_back(to_string(lower) + "->" + to_string(upper));
            }
            
            return res;
        }
        
        if(lower == nums[0] - 1){
            res.push_back(to_string(nums[0] - 1));
        }else if(lower < nums[0] - 1){
            res.push_back(to_string(lower) + "->" + to_string(nums[0] - 1));
        }
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i - 1] == nums[i] - 2){
                res.push_back(to_string(nums[i] - 1));
            }else if(nums[i - 1] < nums[i] - 2){
                res.push_back(to_string(nums[i - 1] + 1) + "->" + to_string(nums[i] - 1));
            }
        }
        
        int n = nums.size() - 1;
        if(nums[n] == upper - 1){
            res.push_back(to_string(upper));
        }else if(nums[n] < upper - 1){
            res.push_back(to_string(nums[n] + 1) + "->" + to_string(upper));
        }
        
        return res;
    }
};