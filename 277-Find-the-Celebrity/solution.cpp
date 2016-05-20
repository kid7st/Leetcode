// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int ans = 0;
        for(int i = 1; i < n; i++)
            if(knows(ans, i)) ans = i;
            
        for(int i = 0; i < n; i++)
            if(i != ans && knows(ans, i) || !knows(i, ans))
                return -1;
        return ans;
    }
};