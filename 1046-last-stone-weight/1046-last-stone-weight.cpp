class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;

        for(int num:stones){
            pq.push(num);
        }
        while(pq.size()>1){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            if(a!=b){
                int c=a-b;
                pq.push(c);
            }
        }
        if(pq.empty()){
            return 0;
        }
        return pq.top();        
    }
};