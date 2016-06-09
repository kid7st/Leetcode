class Solution {
public:
    int rob(vector<int>& nums) {
        int dpRobbed = 0;
        int dpNoRobbed = 0;
        
        for(int num : nums){
            int lastDpRobbed = dpRobbed;
            dpRobbed = dpNoRobbed + num;
            dpNoRobbed = max(dpNoRobbed, lastDpRobbed);
        }
    
        return max(dpNoRobbed, dpRobbed);
    }
};