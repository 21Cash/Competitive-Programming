// Given Undirected Tree, max_dist[i] = max dist from i to any node
vector<int> get_distances(vector<vector<int>> &adj) {
    int N = adj.size();
    
    vector<int> max_dist(N, -1);
    
    auto bfs = [&] (int src) {
        int top;
        queue<int> q;
        vector<int> d(N, -1);
        d[src] = 0;
        max_dist[src] = max(max_dist[src], d[src]);
        q.push(src);
     
        while(!q.empty()) {
            top = q.front();
            q.pop();
     
            for(int v: adj[top]) {
                if(d[v] == -1) {
                    q.push(v);
                    d[v] = d[top] + 1;
                    max_dist[v] = max(max_dist[v], d[v]);
                }
            }
        }
        return top;
    };
    
    int diam_end_1 = bfs(0);
    int diam_end_2 = bfs(diam_end_1);
    
    bfs(diam_end_2);
    
    return max_dist;
}