bool dfs(int u, vector<vector<int> > &graph, vector<int> &vis) {
    vis[u] = 2;
    for (auto &v : graph[u]) {
        if (!vis[v]) {
            if (dfs(v, graph, vis)) return true;
        } else if (vis[v] == 2) return true;
    }
    vis[u] = 1;
    return false;
}

bool bfs(int n, vector<vector<int> > &graph) {
    vector<int> indeg;
    for (int i=0; i<n; ++i) {
        for (auto &v : graph[i]) {
            indeg[v]++;
        }
    }

    queue<int> q;

    for (int i=0; i<n; ++i) 
        if (indeg[i] == 0)
            q.push(i);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto &v : graph[u]) {
            if (--indeg[v] == 0) {
                q.push(v);
            }
        }
    }

    for (auto &ideg : indeg) if (ideg != 0) return true;

    return false;

}