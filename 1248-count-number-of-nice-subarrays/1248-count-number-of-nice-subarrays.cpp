class Solution {
public:
    int solve(
        vector<int>&nums,
        int k
    ){
        int oddSum=0;
        int count=0;
        int left=0;

        for(int right=0;right<nums.size();right++){
    
            if(nums[right]%2==1){
                oddSum++;
            }
            while(oddSum>k){
                if(nums[left]%2==1){
                    oddSum--;
                }
                left++;
            }
            count+=right-left+1;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {

        return solve(nums,k)-solve(nums,k-1);
        
    }
};