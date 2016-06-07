class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 0)
            return 0;
        if(citations[citations.size() - 1] == 0)
            return 0;
            
        int start = 0;
        int end = citations.size() - 1;
        
        while(start < end){
            int mid = start + (end - start) / 2;
            if(citations[mid] >= citations.size() - mid){
                end = mid;
            }else{
                start = mid + 1;
            }
        }
        
        return citations.size() - start;
    }
};