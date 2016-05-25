bool myGreater(int& left, int& right){
    return left > right;
}

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), myGreater);
        int i;
        for(i = 0; i < citations.size() && citations[i] >= i + 1; i++){
        }
        
        return i;
    }
};