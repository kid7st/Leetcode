class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> result(num1.size() + num2.size(), 0);
        
        for(int i = num1.size() - 1; i>=0; i--){
            for(int j = num2.size() - 1; j >= 0; j--){
                int pos1 = i + j;
                int pos2 = pos1 + 1;
                
                int sum = (num1[i] - '0') * (num2[j] - '0') + result[pos2];
                
                result[pos1] += sum / 10;
                result[pos2] = sum % 10;
            }
        }
        
        string res_str = "";
        for(int val : result){
            res_str += to_string(val);
        }
        
        size_t nonzero_pos = res_str.find_first_not_of('0');
        if(nonzero_pos == string::npos){
            return "0";
        }
        
        return res_str.substr(nonzero_pos);
    }
};