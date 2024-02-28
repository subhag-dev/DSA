void dfsUtil(int node, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& result) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfsUtil(neighbor, graph, visited, result);
        }
    }
    result.push(node);
}

vector<int> topologicalSortDFS(vector<vector<int>>& graph, int numNodes) {
    vector<bool> visited(numNodes, false);
    stack<int> result;
    
    for (int i = 0; i < numNodes; ++i) {
        if (!visited[i]) {
            dfsUtil(i, graph, visited, result);
        }
    }

    vector<int> sortedOrder;
    while (!result.empty()) {
        sortedOrder.push_back(result.top());
        result.pop();
    }

    return sortedOrder;
}