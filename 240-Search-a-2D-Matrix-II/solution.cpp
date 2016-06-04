/* Time Complexity = O(logN + logM) */
/* Space Complexity = O(NM) */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)  return false;
        return search(matrix, 0, 0, matrix.size() - 1, matrix[0].size() - 1, target);
    }
    
private:
    bool search(vector<vector<int>>& matrix, int x0, int y0, int x1, int y1, int target){
        if(x0 > x1 || y0 > y1)  return false;
        int centerX = x0 + (x1 - x0) / 2;
        int centerY = y0 + (y1 - y0) / 2;
        if(matrix[centerX][centerY] == target){
            return true;
        }else if(matrix[centerX][centerY] < target){
            return search(matrix, x0, centerY + 1, x1, y1, target) || search(matrix, centerX + 1, y0, x1, centerY, target);
        }else if(matrix[centerX][centerY] > target){
            return search(matrix, x0, y0, x1, centerY - 1, target) || search(matrix, x0, centerY, centerX - 1, y1, target);
        }
        return false;
    }
};