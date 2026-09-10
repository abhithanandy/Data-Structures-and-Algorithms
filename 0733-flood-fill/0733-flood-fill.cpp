class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc,int start, int color) {
        int n=image.size();
        int m=image[0].size();

        if(sr<0 || sr>=n || sc<0 || sc>=m){
            return;
        }
        if(image[sr][sc] != start){
            return;
        }
        image[sr][sc]=color;

        dfs(image,sr+1,sc,start,color);
        dfs(image,sr-1,sc,start,color);
        dfs(image,sr,sc+1,start,color);
        dfs(image,sr,sc-1,start,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int start=image[sr][sc];

        if(start==color){
            return image;
        }    

        dfs(image,sr,sc,start,color);    

        return image;
    }
};