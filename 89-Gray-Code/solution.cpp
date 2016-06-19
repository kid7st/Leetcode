class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0){
            return vector<int>(1, 0);
        }
        
        vector<int> gray = grayCode(n - 1);
        int size = gray.size();
        int padding = 1 << (n - 1);
        for(int i = size - 1; i >= 0; i--){
            gray.push_back(padding + gray[i]);
        }
        
        return gray;
    }
};