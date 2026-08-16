class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int>mp;

        for(char task:tasks){
            mp[task]++;
        }
        
        priority_queue<pair<int, char>>pq;

        for(auto it:mp){
            pq.push({it.second,it.first});
        }

        queue<pair<int,pair<int,char>>>q;

        int time=0;

        while(!pq.empty()|| !q.empty()){
            time++;

            if (!q.empty() && q.front().first == time) {
                pq.push({q.front().second.first,
                         q.front().second.second});
                q.pop();
            }
            if (!pq.empty()) {
                auto [freq, task] = pq.top();
                pq.pop();

                freq--;

                if (freq > 0) {
                    q.push({time + n + 1, {freq, task}});
                }
            }
        }
        return time;

    }
};