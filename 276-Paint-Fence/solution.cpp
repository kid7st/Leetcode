class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0)
            return 0;
        if(n == 1)
            return k;
            
        int first = k;
        int second = k * k;
        
        for(int i = 2; i < n; i++){
            int tmp = second;
            second = first * (k - 1) + second * (k - 1);
            first = tmp;
        }
        
        return second;
    }
};