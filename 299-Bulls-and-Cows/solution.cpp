class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> mp;
        for(char ch : secret){
            mp[ch] += 1;
        }
        
        int aCount = 0;
        int bCount = 0;
        for(int i = 0; i < guess.size(); i++){
            if(guess[i] == secret[i]){
                aCount += 1;
                mp[secret[i]] -= 1;
            }
        }
        
        for(int i = 0; i < guess.size(); i++){
            if(guess[i] != secret[i] && mp[guess[i]] > 0){
                bCount += 1;
                mp[guess[i]] -= 1;
            }
        }
        
        return to_string(aCount) + "A" + to_string(bCount) + "B"; 
    }
};