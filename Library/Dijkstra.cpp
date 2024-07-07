vector<int> dijkstra(int src, vector<vector<pair<int, int>>> &adj) {
    int INF = 2e9;
    int n = adj.size();
    vector<int> dist(n, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        int curDist = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
            
        if(dist[curNode] < curDist) continue;
        
        for(auto &edge : adj[curNode]) {
            int adjNode = edge.first;
            int wt = edge.second;

            int nDist = curDist + wt;
            if(nDist < dist[adjNode]) {
                dist[adjNode] = nDist;
                pq.push({nDist, adjNode});
            }
        }
    }
    return dist;
}