class Solution {
public:
    int countPrimes(int n) {
        if(n < 2)
            return 0;
            
        bool* table = new bool[n];
        for(int i = 2; i < n; i++)
            table[i] = true;
            
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
        delete [] table;
        
        return count;
    }
};