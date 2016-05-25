class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() < 10)
            return {};
            
        unordered_map<string, int> subStringMap;
        vector<string> res;
        
        for(int i = 0; i < s.length() - 9; i++){
            string subStr = s.substr(i, 10);
            if(subStringMap[subStr] == 0){
                subStringMap[subStr] = 1;
            }else if(subStringMap[subStr] == 1){
                res.push_back(subStr);
                subStringMap[subStr] += 1;
            }
        }
        
        return res;
    }
};