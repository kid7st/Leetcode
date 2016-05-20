class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        
        if(lower == nums[0] - 2){
            res.push_back(to_string(nums[0] - 1));
        }else if(lower < nums[0] - 2){
            res.push_back(to_string(lower + 1) + "->" + to_string(nums[0] - 1));
        }
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i - 1] == nums[i] - 2){
                res.push_back(to_string(nums[i] - 1));
            }else if(nums[i - 1] < nums[i] - 2){
                res.push_back(to_string(nums[i - 1] + 1) + "->" + to_string(nums[i] - 1));
            }
        }
        
        int n = nums.size() - 1;
        if(nums[n] == upper - 2){
            res.push_back(to_string(upper - 1));
        }else if(nums[n] < upper - 2){
            res.push_back(to_string(nums[n] + 1) + "->" + to_string(upper - 1));
        }
        
        return res;
    }
};