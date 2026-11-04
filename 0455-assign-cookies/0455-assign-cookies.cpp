class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int count = 0;
        int j = 0;

        for(int i = 0; i < g.size() && j < s.size(); i++) {
            if(s[j] >= g[i]) {
                count++;
                j++;
            }
            else {
                j++;
                i--; 
            }
        }

        return count;
    }
};