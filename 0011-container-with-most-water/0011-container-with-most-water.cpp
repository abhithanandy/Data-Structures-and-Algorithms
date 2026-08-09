class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int area=0;
        int maxAr=0;

        while(left<right){
            int len=min(height[left],height[right]);
            int wid=right-left;
            area=len*wid;
            maxAr=max(area,maxAr);

            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxAr;
        
    }
};