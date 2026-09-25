class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int j=0;//first pointer

        for(int i=1;i<n;i++){ //second comparing pointer
            if(nums[i]!=nums[j]){
                nums[j+1]=nums[i];
                j++;
            }
        }

        return j+1;
        
    }
};