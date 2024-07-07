const int INF = 2e9;
vector<vector<int>> floyd(const vector<vector<pair<int, int>>>& graph) {
    int V = graph.size();
    vector<vector<int>> dist(V, vector<int>(V, INF));

    for (int i = 0; i < V; ++i) {
        dist[i][i] = 0;
        for (const auto& [j, weight] : graph[i])
            dist[i][j] = min(dist[i][j], weight);
    }

    for (int k = 0; k < V; ++k)
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    return dist;
}