class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size() < 3)
            return 0;
        sort(nums.begin(), nums.end());
        
        int count = 0;
        for(int i = 0; i<nums.size() - 2; i++){
            int k = nums.size() - 1;
            for(int j = i + 1; j < nums.size() - 1 && k > j; j++){
                while(k > j && nums[i] + nums[j] + nums[k] >= target)
                    k--;
                    
                count += k - j;
                if(k == j)
                    break;
            }
        }
        
        return count;
    }
};