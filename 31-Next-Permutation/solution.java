public class Solution {
    public void nextPermutation(int[] nums) {
        int len = nums.length;
        
        if(len <= 1) {
            return;
        }
        
        int i;
        for( i=len-1; i>0; i--) {
            if (nums[i] > nums[i-1]) {
                break;
            }
        }

       //System.out.println(i);
        if(i > 0) {
            for(int j=len-1; j>=i; j--) {
                if(nums[j] > nums[i-1]) {
                    int temp = nums[j];
                    nums[j] = nums[i-1];
                    nums[i-1] = temp;
                    break;
                }
            }     
        }
        
        for(int j=i, k=len-1; j<k; j++,k--) {
            int temp = nums[j];
            nums[j] = nums[k];
            nums[k] = temp;
        }
        
        
    }
}