class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        //dp[i] means the size of the longest increasing subsequence ends with the nums[i]
        vector<int> dp(nums.size(), 1);
        
        int maxDp = 1;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxDp = max(maxDp, dp[i]);
        }
        
        return maxDp;
    }
};