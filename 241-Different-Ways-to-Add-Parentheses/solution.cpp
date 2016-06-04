class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        if(input.size() == 0) return {};
        vector<int> res;
        for(int i = 0; i < input.size(); i++){
            if(input[i] != '+' && input[i] != '-' && input[i] != '*') continue;
            
            auto valLeft = diffWaysToCompute(input.substr(0, i));
            auto valRight = diffWaysToCompute(input.substr(i + 1));
            
            for(int val1 : valLeft){
                for(int val2 : valRight){
                    if(input[i] == '+') res.push_back(val1 + val2);
                    if(input[i] == '-') res.push_back(val1 - val2);
                    if(input[i] == '*') res.push_back(val1 * val2);
                }
            }
        }
        
        if(res.empty())
            return vector<int>{stoi(input)};
        else
            return res;
    }
};