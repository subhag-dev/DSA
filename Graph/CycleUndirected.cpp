#define pii pair<int, int>

void bfs(vector<vector<int> > &graph) {
    vector<bool> vis(n, false);
    queue<pii> q;
    q.push({0, -1});
    vis[0] = true;
    while (!q.empty()) {
        auto [u, par] = q.front();
        q.pop();
        for (auto &v : graph[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            } else if (v != par) {
                return true;
            }
        }
    }
    return false;
}

void dfs(int u, int par, vector<vector<int> > &graph) {
    vis[u] = true;
    for (auto &v : graph[u]) {
        if (!vis[v]) {
            if (dfs(v, u, graph))
                return true;
        } else if (v != par) {
            return true;
        }
    }
    return false;
}