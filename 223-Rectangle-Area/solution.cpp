class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C - A)*(D - B);
        int area2 = (G - E)*(H - F);
        
        int maxLeft = max(A, E);
        int minRight = min(C, G);
        int maxBottom = max(B, F);
        int minTop = min(D, H);
        
        if(maxLeft >= minRight || maxBottom >= minTop)
            return area1 + area2;
        else
            return area1 + area2 - (minRight - maxLeft)*(minTop - maxBottom);
    }
};