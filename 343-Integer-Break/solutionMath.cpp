class Solution {
public:
    int integerBreak(int n) {
        if(n == 2)  return 1;
        if(n == 3)  return 2;
        if(n%3 == 1) return binPow(3, (n - 4)/3) * 4;
        if(n%3 == 2) return binPow(3, (n - 2)/3) * 2;
        return binPow(3, n/3);
    }
    
private:
    int binPow(int base, int n){
        int ans = 1;
        while(n){
            if(n & 1) ans *= base;
            base = base*base;
            n >>= 1;
        }
        
        return ans;
    }
};