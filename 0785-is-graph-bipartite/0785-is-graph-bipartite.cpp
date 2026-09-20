class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,0);

        for(int i=0;i<n;i++){
            if(color[i]!=0){
                continue;
            }
            queue<int>q;

            color[i]=1;
            q.push(i);

            while(!q.empty()){
                int node=q.front();
                q.pop();

                for(int neighbour:graph[node]){
                    if(color[neighbour]==0){
                        color[neighbour]=-color[node];
                        q.push(neighbour);

                    }
                    else if(color[neighbour]==color[node]){
                        return false;
                    }

                }
            }
        }
        return true;
        
    }
};