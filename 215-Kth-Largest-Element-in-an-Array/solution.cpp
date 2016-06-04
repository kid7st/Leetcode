/* Quick Select
Average Time Complexity = O(2N) 
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, 0, nums.size() - 1, k - 1);
    }

private:
    int findKthLargest(vector<int>& nums, int start, int end, int k){
        int pos = partition(nums, start, end);
        
        if(pos == k){
            return nums[pos];
        }else if(pos < k){
            return findKthLargest(nums, pos + 1, end, k);
        }else if(pos > k){
            return findKthLargest(nums, start, pos - 1, k);
        }
        
        return 0;
    }
    
    int partition(vector<int>& nums, int start, int end){
        int pivot = nums[end];
        int i = start - 1;
        for(int j = start; j < end; j++){
            if(nums[j] >= pivot){
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[end]);
        
        return i + 1;
    }
};