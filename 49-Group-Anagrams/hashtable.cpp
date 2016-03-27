class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        vector<vector<string>> groups;
        
        for(int i = 0; i < strs.size(); i++){
            string key = strs[i];
            sort(key.begin(), key.end());
            hash[key].push_back(strs[i]);
        }
        
        for(auto it = hash.begin(); it != hash.end(); it++){
            sort(it->second.begin(), it->second.end());
            groups.push_back(it->second);
        }
        
        return groups;
    }
};