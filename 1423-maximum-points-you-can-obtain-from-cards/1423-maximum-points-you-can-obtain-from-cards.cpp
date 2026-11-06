class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totalPts=0;

        for(int i=0;i<cardPoints.size();i++){
            totalPts+=cardPoints[i];
        }
        int windowSize=cardPoints.size()-k;
        int windowSum=0;

        for(int i=0;i<windowSize;i++){
            windowSum+=cardPoints[i];
        }

        int minWindowSum=windowSum;

        for(int i=windowSize;i<cardPoints.size();i++){
            windowSum-=cardPoints[i-windowSize];
            windowSum+=cardPoints[i];   
            minWindowSum=min(minWindowSum,windowSum);
       
        }
        return totalPts-minWindowSum;         
        
    }
};