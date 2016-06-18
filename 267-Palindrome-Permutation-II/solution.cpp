class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        if(s.size() == 1){
            res.push_back(s);
            return res;
        }
        unordered_map<char, int> counts;
        for(char ch : s) counts[ch]++;
        int odd = 0;
        char mid;
        string half;
        for(auto item : counts){
            if(item.second & 1){
                ++odd;
                mid = item.first;
                if(odd > 1) return res;
            }
            half += string(item.second / 2, item.first);
        }
        
        generatePalindromes(half, 0, res);
        
        for(int i = 0; i < res.size(); i++){
            string p = res[i];
            reverse(p.begin(), p.end());
            
            if(odd)
                res[i] += string(1, mid) + p;
            else
                res[i] += p;
        }
        
        return res;
    }

private:
    void generatePalindromes(string s, int begin, vector<string> &acc){
        if(begin == s.size() - 1){
            acc.push_back(s);
        }
        
        for(int i = begin; i < s.size(); i++){
            if(!isRepeat(s, begin, i)){
                swap(s[begin], s[i]);
                generatePalindromes(s, begin + 1, acc);
                swap(s[i], s[begin]);
            }
        }
    }
    
    bool isRepeat(const string &s, int begin, int end){
        for(; begin < end; begin++){
            if(s[begin] == s[end])
                return true;
        }
        
        return false;
    }
};