class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> hash;
        for(int num : nums1){
            hash.insert(num);
        }
       
        set<int> undup;
        for(int num : nums2){
            if(hash.find(num) != hash.end())
                undup.insert(num);
        }
        
        vector<int> res;
        for(int num : undup){
            res.push_back(num);
        }
        
        return res;
    }
};