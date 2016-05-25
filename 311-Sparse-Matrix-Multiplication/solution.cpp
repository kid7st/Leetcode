typedef pair<pair<int, int>, int> Triple;

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        if(A.empty() || B.empty())
            return vector<vector<int>>();
        vector<Triple> mapA, mapB;
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < A[i].size(); j++){
                if(A[i][j] != 0){
                    Triple tmp(pair<int, int>(i, j), A[i][j]); 
                    mapA.push_back(tmp);
                }
            }
        }
        
        for(int i = 0; i < B.size(); i++){
            for(int j = 0; j < B[i].size(); j++){
                if(B[i][j] != 0){
                    Triple tmp(pair<int, int>(i, j), B[i][j]);
                    mapB.push_back(tmp);
                }
            }
        }
        
        vector<vector<int>> C(A.size(), vector<int>(B[0].size(), 0));
        for(int i = 0; i < mapA.size(); i++){
            for(int j = 0; j < mapB.size(); j++){
                if(mapA[i].first.second == mapB[j].first.first){
                    C[mapA[i].first.first][mapB[j].first.second] += mapA[i].second * mapB[j].second;
                }
            }
        }
        
        return C;
    }
};