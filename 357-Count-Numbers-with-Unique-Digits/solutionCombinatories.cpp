class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        int count = 10;
        for(int i = 2; i <= n; i++){
            count += combinatories(i);
        }
        return count;
    }
    
private:
    int combinatories(int n){
        int count = 9;
        for(int k = 9, i = 1; i < n; i++, k--){
            count *= k;
        }
        
        return count;
    }
};