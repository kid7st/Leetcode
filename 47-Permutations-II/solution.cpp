class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        permuteUnique(nums, 0, res);
        return res;
    }
    
private:
    bool isRepeat(vector<int>& nums, int begin, int end){
        for(; begin < end; begin++){
            if(nums[begin] == nums[end]) return true;
        }
        return false;
    }
    
    void permuteUnique(vector<int>& nums, int begin, vector<vector<int>> &acc){
        if(begin == nums.size() - 1){
            acc.push_back(nums);
            return;
        }
        
        for(int i = begin; i < nums.size(); i++){
            if(!isRepeat(nums, begin, i)){
                swap(nums[begin], nums[i]);
                permuteUnique(nums, begin + 1, acc);
                swap(nums[i], nums[begin]);
            }
        }
    }
    
    
};