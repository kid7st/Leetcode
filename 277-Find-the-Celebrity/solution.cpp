// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        vector<bool> isCelebrity = vector<bool>(n, true);
        vector<int> count = vector<int>(n, 0);
        
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(knows(j, i)){
                    isCelebrity[j] = false;
                    count[i]++;
                }
                
                if(knows(i, j)){
                    isCelebrity[i] = false;
                    count[j]++;
                }
            }
            
            if(isCelebrity[i] && count[i])
                return i;
        }
        
        return false;
    }
};