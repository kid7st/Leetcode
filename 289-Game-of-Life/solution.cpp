class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                int count = countLive(board, i, j);
                if(board[i][j] == 0 || board[i][j] == 2){
                    if(count == 3)
                        board[i][j] = 3;
                    else
                        board[i][j] = 0;
                }else if(board[i][j] == 1 || board[i][j] == 3){
                    if(count < 2)
                        board[i][j] = 2;
                    else if(count > 3)
                        board[i][j] = 2;
                    else
                        board[i][j] = 1;
                }
            }
        }
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == 1 || board[i][j] == 3)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }
        }
    }
    
private:
    int horizontal[3] = {-1, 0, 1};
    int vertical[3] = {-1, 0, 1};
    
    int countLive(vector<vector<int>>& board, int x, int y){
        int count = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(horizontal[i] == 0 && vertical[j] == 0)
                    continue;
                if(x + horizontal[i] < 0 || x + horizontal[i] >= board.size())
                    continue;
                if(y + vertical[j] < 0 || y + vertical[j] >= board[x].size())
                    continue;
                
                if(board[x + horizontal[i]][y + vertical[j]] == 1 |
                    board[x + horizontal[i]][y + vertical[j]] == 2){
                    count += 1;
                }
            }
        }
        return count;
    }
};