class Solution {
public:

    bool dfs(int course, vector<vector<int>>& graph,
             vector<int>& visited) {

        // Currently visiting this course
        if (visited[course] == 1)
            return false;

        // Already completely checked
        if (visited[course] == 2)
            return true;

        visited[course] = 1;

        for (int next : graph[course]) {

            if (!dfs(next, graph, visited))
                return false;
        }

        // Finished checking this course
        visited[course] = 2;

        return true;
    }

    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);
        vector<int> visited(numCourses, 0);

        for (auto p : prerequisites) {

            int course = p[0];
            int prerequisite = p[1];

            graph[prerequisite].push_back(course);
        }

        for (int i = 0; i < numCourses; i++) {

            if (!dfs(i, graph, visited))
                return false;
        }

        return true;
    }
};