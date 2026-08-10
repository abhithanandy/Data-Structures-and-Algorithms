class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=prices[0];
        int prof=0;

        for(int i=1;i<prices.size();i++){
            minPrice=min(minPrice,prices[i]);
            prof=max(prof,prices[i]-minPrice);
        }
        return prof;
    }
        
};