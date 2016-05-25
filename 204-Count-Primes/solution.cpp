class Solution {
public:
    int countPrimes(int n) {
        if(n < 2)
            return 0;
            
        vector<bool> table(n, true);
        int count = 0;
        for(int i = 2; i < n; i++){
            if(table[i]){
                 count += 1;
                 int j = 2;
                 for(int j = i + i; j < n; j += i){
                     table[j] = false;
                 }
            }
        }
        
        return count;
    }
};