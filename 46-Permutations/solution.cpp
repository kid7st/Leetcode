class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permute(nums, 0, res);
        return res;
    }
    
private:
    void permute(vector<int>& nums, int begin, vector<vector<int>>& acc){
        if(begin == nums.size() - 1){
            acc.push_back(nums);
            return;
        }
        
        for(int i = begin; i < nums.size(); i++){
            swap(nums[begin], nums[i]);
            permute(nums, begin + 1, acc);
            swap(nums[i], nums[begin]);
        }
    }
};