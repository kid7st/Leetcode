class Solution {
public:
    vector<vector<string>> partition(string s) {
        if(s.empty())
            return vector<vector<string>>(1, vector<string>());
           
        if(cache.find(s) != cache.end())
            return cache[s];
            
        vector<vector<string>> res;
        for(int i = s.size() - 1; i >= 0; i--){
            string tail = s.substr(i);
            if(isPalindrome(tail)){
                string head = s.substr(0, i);
                vector<vector<string>> headPartition = partition(head);
                for(vector<string> part : headPartition){
                    part.push_back(tail);
                    res.push_back(part);
                }
            }
        }
        
        cache[s] = res;
        return res;
    }
    
private:
    unordered_map< string, vector<vector<string>> > cache;
    
    bool isPalindrome(string s){
        for(int i = 0; i < s.size() / 2; i++){
            if(s[i] != s[s.size() - 1 - i])
                return false;
        }
        return true;
    }
};