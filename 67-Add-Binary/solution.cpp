class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        char carry = '0';
        while(i >= 0 && j >= 0){
            if(a[i] == '0' && b[j] == '0'){
                res += carry;
                carry = '0';
            }else if(a[i] == '1' && b[j] == '1'){
                res += carry;
                carry = '1';
            }else{
                if(carry == '0'){
                    res += '1';
                    carry = '0';
                }else{
                    res += '0';
                    carry = '1';
                }
            }
            i--;
            j--;
        }
        
        while(i >= 0){
            if(a[i] == '0'){
                res += carry;
                carry = '0';
            }else{
                if(carry == '0'){
                    res += '1';
                    carry = '0';
                }else{
                    res += '0';
                    carry = '1';
                }
            }
            i--;
        }
        while(j >= 0){
            if(b[j] == '0'){
                res += carry;
                carry = '0';
            }else{
                if(carry == '0'){
                    res += '1';
                    carry = '0';
                }else{
                    res += '0';
                    carry = '1';
                }
            }
            j--;
        }
        
        if(carry == '1'){
            res += '1';
        }
        
        for(int i = 0; i < res.length() / 2; i++){
            swap(res[i], res[res.length() - 1 - i]);
        }
        
        return res;
    }
};