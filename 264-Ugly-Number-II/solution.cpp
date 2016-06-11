class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1) return 1;
        int l2 = 1, l3 = 1, l5 = 1;
        vector<int> uglys = {0, 1};
        while(n > 1){
            int cur = min( uglys[l2]*2, min(uglys[l3]*3, uglys[l5]*5) );
            uglys.push_back(cur);
            
            if(uglys[l2]*2 == cur) l2++;
            if(uglys[l3]*3 == cur) l3++;
            if(uglys[l5]*5 == cur) l5++;
            n--;
        }
        
        return uglys.back();
    }
};