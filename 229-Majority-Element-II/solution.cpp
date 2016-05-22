class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        return majorityElement(nums, 3);
    }
    
private:
    vector<int> majorityElement(vector<int>& nums, int k) {
        if(k < 2 || nums.empty())
            return vector<int>();
        
        vector<int> candidates(k - 1, nums[0]);
        vector<int> counts(k - 1, 0);
        for(int num : nums){
            auto pos = find(candidates.begin(), candidates.end(), num);
            if(pos != candidates.end()){
                counts[pos - candidates.begin()] += 1;
            }else{
                bool find_sign = false;
                for(auto i = 0; i < counts.size(); i++){
                    if(counts[i] == 0){
                        find_sign = true;
                        candidates[i] = num;
                        counts[i] = 1;
                        break;
                    }
                }
                
                if(!find_sign){
                    for(int i = 0; i < counts.size(); i++)
                        counts[i] -= 1;
                }
            }
        }
        
        vector<int> res;
        int require = nums.size() / k;
        for(int i = 0; i < candidates.size(); i++){
            if(counts[i] && count(nums.begin(), nums.end(), candidates[i]) > require)
                res.push_back(candidates[i]);
        }
        
        return res;
    }
};