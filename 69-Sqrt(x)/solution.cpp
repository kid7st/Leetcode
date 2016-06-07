class Solution {
public:
    int mySqrt(int x) {
        double y = x;
        while(abs(y*y / x - 1) > 0.000000000001){
            y = (y + x/y)/2;
        }
        
        return y;
    }
};