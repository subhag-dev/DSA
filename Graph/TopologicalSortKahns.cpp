vector<int> topologicalSortKahn(vector<vector<int>>& graph, int numNodes) {
    vector<int> indegree(numNodes, 0);
    for (int i = 0; i < numNodes; ++i) {
        for (int neighbor : graph[i]) {
            indegree[neighbor]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < numNodes; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> sortedOrder;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        sortedOrder.push_back(node);
        for (int neighbor : graph[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return sortedOrder;
}