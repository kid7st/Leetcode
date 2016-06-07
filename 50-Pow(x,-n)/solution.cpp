class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(n == 1)
            return x;
        if(n == -1)
            return 1/x;
        
        if(n%2 == 0){
            double y = myPow(x, n / 2);
            return y * y;
        }else{
            double y = myPow(x, n / 2);
            if(n > 0)
                return y * y * x;
            else
                return y * y * 1/x;
        }
        
        return 0;
    }
};