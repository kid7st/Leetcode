// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 0;
        int end = n;
        while(start < end){
            int mid = start + (end - start) / 2;
            if(isBadVersion(mid)){
                end = mid;
            }else{
                start = mid + 1;
            }
        }
        
        return start;
    }
};