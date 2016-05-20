// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        vector<bool> isCelebrity = vector<bool>(n, true);
        vector<int> count = vector<int>(n, 0);
        
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(knows(i, j)){
                    isCelebrity[i] = false;
                    count[j]++;
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            if(isCelebrity[i] && count[i] == n - 1)
                return i;
        }
        
        return -1;
    }
};