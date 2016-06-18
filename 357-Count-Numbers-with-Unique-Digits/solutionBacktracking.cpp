class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int count = 1;
        vector<bool> bitmap(10, 0);
        for(int i = 1; i <= 9; i++){
            bitmap[i] = true;
            dfs(i, 1, n, bitmap, count);
            bitmap[i] = false;
        }
        return count;
    }
    
private:
    void dfs(int current, int steps, int n, vector<bool>& bitmap, int &count){
        if(steps > n)
            return;
        else
            count += 1;
            
        for(int i = 0; i <= 9; i++){
            if(!bitmap[i]){
                bitmap[i] = true;
                dfs(current*10 + i, steps + 1, n, bitmap, count);
                bitmap[i] = false;
            }
        }
    }
};