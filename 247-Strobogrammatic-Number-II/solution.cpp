class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        if(n == 0) return {""};
        if(n == 1) return {"0", "1", "8"};
        if(n == 2) return {"11", "69", "88", "96"};
        
        return findStrobogrammatic(n, n);
    }
    
    vector<string> findStrobogrammatic(int n, int target){
        if(n == 0) return {""};
        if(n == 1) return {"0", "1", "8"};
        if(n == 2) return {"00", "11", "69", "88", "96"};
        vector<string> res;
        vector<string> next2 = findStrobogrammatic(n - 2, target);
        
        for(string item : next2){
            res.push_back(string("1") + item + string("1"));
            res.push_back(string("6") + item + string("9"));
            res.push_back(string("8") + item + string("8"));
            res.push_back(string("9") + item + string("6"));
            if(n != target) res.push_back(string("0") + item + string("0"));
        }
        return res;
    }
};