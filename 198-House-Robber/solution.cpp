class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        vector<int> dpRobbed(nums.size(), 0);
        vector<int> dpNoRobbed(nums.size(), 0);
        dpRobbed[0] = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            dpRobbed[i] = dpNoRobbed[i - 1] + nums[i];
            if(dpNoRobbed[i - 1] > dpRobbed[i - 1]){
                dpNoRobbed[i] = dpNoRobbed[i - 1];
            }else{
                dpNoRobbed[i] = dpRobbed[i - 1];
            }
            
            dpNoRobbed[i] = max(dpNoRobbed[i - 1], dpRobbed[i - 1]);
        }
    
        return max(dpNoRobbed[nums.size() - 1], dpRobbed[nums.size() - 1]);
    }
};