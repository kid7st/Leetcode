struct Matrix {
    int m[2][2];
};

class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0)
            return 0;
        if(n == 1)
            return k;
        if(n == 2)
            return k * k;
            
        int first = k;
        int second = k * k;
        
        Matrix base;
        base.m[0][0] = 0;
        base.m[0][1] = 1;
        base.m[1][0] = k - 1;
        base.m[1][1] = k - 1;
        
        base = matrixPow(base, n - 2);
        return first * base.m[1][0] + second * base.m[1][1];
    }
    
private:
    Matrix multi(Matrix a, Matrix b){
        Matrix res;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                res.m[i][j] = 0;
                for(int k = 0; k < 2; k++)
                    res.m[i][j] = res.m[i][j] + a.m[i][k]*b.m[k][j];
            }
        }
        return res;
    }
    
    Matrix matrixPow(Matrix a, int n){
        Matrix ans;
        ans.m[0][0] = ans.m[1][1] = 1;
        ans.m[0][1] = ans.m[1][0] = 0;
        while(n){
            if(n & 1) ans = multi(ans, a);
            a = multi(a, a);
            n >>= 1;
        }
        
        return ans;
    }
};