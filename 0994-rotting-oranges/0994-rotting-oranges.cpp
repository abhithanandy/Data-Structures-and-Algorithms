class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<pair<int,int>> rotten;
        
        // Store initially rotten oranges
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    rotten.push_back({i, j});
                }
            }
        }

        int minutes = 0;

        while(!rotten.empty()) {

            vector<pair<int,int>> next;

            for(auto p : rotten) {

                int i = p.first;
                int j = p.second;

                // Down
                if(i + 1 < n && grid[i+1][j] == 1) {
                    grid[i+1][j] = 2;
                    next.push_back({i+1, j});
                }

                // Up
                if(i - 1 >= 0 && grid[i-1][j] == 1) {
                    grid[i-1][j] = 2;
                    next.push_back({i-1, j});
                }

                // Right
                if(j + 1 < m && grid[i][j+1] == 1) {
                    grid[i][j+1] = 2;
                    next.push_back({i, j+1});
                }

                // Left
                if(j - 1 >= 0 && grid[i][j-1] == 1) {
                    grid[i][j-1] = 2;
                    next.push_back({i, j-1});
                }
            }

            rotten = next;
            minutes++;
        }

        // Check for remaining fresh oranges
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1)
                    return -1;
            }
        }

        return minutes == 0 ? 0 : minutes - 1;
    }
};