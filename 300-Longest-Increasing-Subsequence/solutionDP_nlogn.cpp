class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        //dp[i] is the minimum number that is the end of the longest increasing subsequence with lenght i
        vector<int> dp;
        
        for(int num : nums){
            int idx = binSearch(dp, num);
            if(idx >= dp.size()){
                dp.push_back(num);
            }else{
                dp[idx] = num;
            }
        }
        
        return dp.size();
    }
private:
    int binSearch(vector<int>& dp, int target){
        int begin = 0;
        int end = dp.size();
        while(begin < end){
            int mid = begin + (end - begin) / 2;
            if(target > dp[mid]){
                begin = mid + 1;
            }else{
                end = mid;
            }
        }
        
        return begin;
    }
};