class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x != 0){
            if(INT_MAX / 10 < res || INT_MIN / 10 > res){
                res = 0;
                break;
            }
            res = res*10 + x % 10;
            x /= 10;
        }
        
        return res;
    }
};