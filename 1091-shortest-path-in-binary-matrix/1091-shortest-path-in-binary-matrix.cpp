class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] != 0 || grid[n-1][m-1] != 0){
            return -1;
        }

        queue<pair<pair<int,int>,int>> q;

        q.push({{0,0},1});

        grid[0][0] = 1;

        vector<pair<int,int>> neighbours = {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0},
            {1,1},
            {-1,-1},
            {1,-1},
            {-1,1}
        };

        while(!q.empty()){

            pair<int,int> p = q.front().first;

            int x = p.first;
            int y = p.second;

            int lengthOfPath = q.front().second;

            q.pop();

            if(x == n-1 && y == m-1){
                return lengthOfPath;
            }

            for(pair<int,int> neighbour : neighbours){

                int newX = x + neighbour.first;
                int newY = y + neighbour.second;

                if(newX >= 0 && newX < n &&
                   newY >= 0 && newY < m &&
                   grid[newX][newY] == 0){

                    grid[newX][newY] = 1;

                    q.push({{newX,newY}, lengthOfPath + 1});
                }
            }
        }

        return -1;
    }
};