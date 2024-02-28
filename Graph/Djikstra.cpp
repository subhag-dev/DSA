#define pii pair<int, int>

vector<int> dijkstra(const vector<vector<pii>>& graph, int start) {
    int n = graph.size();
    vector<int> distances(n, numeric_limits<int>::max());
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    distances[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) { // while there are better {distance, node} pairs left to be processed
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        if (dist_u > distances[u]) // Ignore outdated entries in priority queue
            continue;

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist_u + weight < distances[v]) {
                distances[v] = dist_u + weight;
                pq.push(make_pair(distances[v], v));
            }
        }
    }

    return distances;
}