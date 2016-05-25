class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size() != 9 || board[0].size() != 9)
            return false;
            
        for(int i = 0; i < 9; i++){
            vector<bool> table(9, false);
            for(int j = 0; j < 9; j++){
                if(board[i][j] >= '1' && board[i][j] <= '9'){
                    if(!table[board[i][j] - '0'])
                        table[board[i][j] - '0'] = true;
                    else
                        return false;
                }
            }
        }
        
        for(int j = 0; j < 9; j++){
            vector<bool> table(9, false);
            for(int i = 0; i < 9; i++){
                if(board[i][j] >= '1' && board[i][j] <= '9'){
                    if(!table[board[i][j] - '0'])
                        table[board[i][j] - '0'] = true;
                    else
                        return false;
                }
            }
        }
        
        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                vector<bool> table(9, false);
                for(int x = i; x < i + 3; x++){
                    for(int y = j; y < j + 3; y++){
                        if(board[x][y] >= '1' && board[x][y] <= '9'){
                            if(!table[board[x][y] - '0'])
                                table[board[x][y] - '0'] = true;
                            else
                                return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};