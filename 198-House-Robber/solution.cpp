class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        int dpRobbed = nums[0];
        int dpNoRobbed = 0;
        
        for(int i = 1; i < nums.size(); i++){
            int lastDpRobbed = dpRobbed;
            dpRobbed = dpNoRobbed + nums[i];
            
            dpNoRobbed = max(dpNoRobbed, lastDpRobbed);
        }
    
        return max(dpNoRobbed, dpRobbed);
    }
};