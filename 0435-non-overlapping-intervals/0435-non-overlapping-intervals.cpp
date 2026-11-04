class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n=intervals.size();
        int count=0;
        int prev=0;

        for(int i=1;i<n;i++){
            if(intervals[prev][1]<=intervals[i][0]){
                prev=i;
            }
            else{
                count++;
                if(intervals[prev][1]>intervals[i][1]){
                    prev=i;
                }
            }
        }
        return count;
        
    }
};