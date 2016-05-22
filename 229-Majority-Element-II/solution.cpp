class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size() == 0)
            return vector<int>();
            
        int candidate1 = nums[0];
        int candidate2 = nums[1];
        int count1 = 0;
        int count2 = 0;
        
        for(int num : nums){
            if(num == candidate1)
                count1++;
            else if(num == candidate2)
                count2++;
            else{
                if(count1 == 0){
                    candidate1 = num;
                    count1 = 1;
                    continue;
                }else if(count2 == 0){
                    candidate2 = num;
                    count2 = 1;
                    continue;
                }
                
                count1--;
                count2--;
            }
        }
        
        vector<int> res;
        int require = nums.size() / 3;
        if(count1 && count(nums.begin(), nums.end(), candidate1) > require)
            res.push_back(candidate1);
        if(count2 && count(nums.begin(), nums.end(), candidate2) > require)
            res.push_back(candidate2);
            
        return res;
    }
};