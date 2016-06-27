/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int sum = 0;
        dfs(nestedList, 1, sum);
        return sum;
    }
    
private:
    void dfs(const vector<NestedInteger> &nestedList, int depth, int &sum){
        for(NestedInteger item : nestedList){
            if(item.isInteger()){
                sum += depth * item.getInteger();
            }else{
                dfs(item.getList(), depth + 1, sum); 
            }
        }
        return;
    }
};