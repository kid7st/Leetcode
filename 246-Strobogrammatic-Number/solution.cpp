class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> strobo;
        strobo['0'] = '0';
        strobo['1'] = '1';
        strobo['6'] = '9';
        strobo['8'] = '8';
        strobo['9'] = '6';
        
        for(int i = 0; i <= (num.size() - 1) / 2; i++){
            if(strobo.find(num[i]) == strobo.end())
                return false;
            if(strobo[num[i]] != num[num.size() - 1 - i])
                return false;
        }
        
        return true;
    }
};