class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k < 1 || t < 0) return false;
        multiset<int> window;
        for(int i = 0; i < nums.size(); i++){
            window.insert(nums[i]);
            auto it = window.find(nums[i]); //minimal nums that >= nums[i]
            if(it != (--window.end()) && *(++it) <= t + nums[i]) return true;
            it = window.find(nums[i]); //max nums that <= nums[i]
            if(it != window.begin() && nums[i] <= t + *(--it)) return true;
            
            if(i >= k) window.erase(nums[i - k]);
        }
        return false;
    }
};