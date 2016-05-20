class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        vector<int> res;
        for(int i = 0; i < numbers.size() - 1; i++){
            while(i < j && numbers[i] + numbers[j] > target)
                j--;
            if(numbers[i] + numbers[j] == target){
                res.push_back(i + 1);
                res.push_back(j + 1);
                break;
            }
        }
        
        return res;
    }
};