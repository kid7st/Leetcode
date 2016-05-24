class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> groups;
        
        for(string str : strings){
            mp[getBase(str)].push_back(str);
        }
        
        for(auto pair : mp){
            vector<string> group = pair.second;
            sort(group.begin(), group.end());
            groups.push_back(group);
        }
        
        return groups;
    }
    
private:
    string getBase(string str){
        int offset = str[0] - 'a'; 
        for(int i = 0; i < str.size(); i++){
            str[i] = char(int(str[i] - 'a' - offset + 26) % 26 + 'a');
        }
        
        return str;
    }    
};