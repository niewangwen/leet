class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> indegrees(numCourses);
        queue<int> q;
        for (auto pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            indegrees[pre[0]]++;
        }
        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int free_node = q.front();
            q.pop();
            res.push_back(free_node);
            for (auto node : graph[free_node]) {
                indegrees[node]--;
                if (indegrees[node] == 0)
                    q.push(node);
            }
        }
        for (auto indegree : indegrees) {
            if (indegree != 0)
                return {};
        }
        return res;
    }
};
