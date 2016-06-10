class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        
        //Didn't rob first house
        int robbed = 0;
        int noRobbed = 0;
        for(int i = 1; i < nums.size(); i++){
            int tmp = robbed;
            robbed = noRobbed + nums[i];
            noRobbed = max(tmp, noRobbed);
        }
        int noRobbedFirst = max(robbed, noRobbed);
        
        //rob first house
        robbed = nums[0];
        noRobbed = 0;
        for(int i = 1; i < nums.size(); i++){
            int tmp = robbed;
            robbed = noRobbed + nums[i];
            noRobbed = max(tmp, noRobbed);
        }
        
        return max(noRobbedFirst, noRobbed);
    }
};