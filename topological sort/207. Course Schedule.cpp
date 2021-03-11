class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> indegree(numCourses);
        queue<int> q;
        for (auto iter : prerequisites) {
            //build a graph at first, and this graph indicates each node's relation
            //if node j relies on node j, then j should be included in graph[i]
            graph[iter[1]].push_back(iter[0]);
            //build an indegree array then
            //this indicates how many nodes should be visited before visiting current node
            //if indegree[i] == 1, it means before visiting node i, we need to visit 1 node
            //if indegree[i] == 0, it means node i has not dependency, thus it can be visited directly
            indegree[iter[0]]++;
        }
        for (int i = 0; i < numCourses; i++) {
            //we use a queue to record the node which can be visited without dependency
            //in other words, we put node whose indegree == 0 into the queue
            if (indegree[i] == 0)
                q.push(i);
        } 
        while (!q.empty()) {
            //and then we traverse the queue
            //this means we visit the front node of the queue
            int cur_node = q.front();
            q.pop();
            for (auto node : graph[cur_node]) {
                //since cur_node is visited, all the nodes dependent on cur_node should minus their indegree
                indegree[node]--;
                //if any node's indegree == 0, it means it can be visited directly, so we put it into the queue
                if (indegree[node] == 0)
                    q.push(node);
            }
        }
        for (auto in : indegree) {
            //at last, we traverse all the nodes, if any node's indegree still larger than 0,
            //it means that there's a cycle in the graph which we can't fix
            if (in != 0)
                return false;
        }
        return true;
    }
};
