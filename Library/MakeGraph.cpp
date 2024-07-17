vector<vector<int>> make_graph(int N, vector<vector<int>> &edges, bool directed = false) {
    vector<vector<int>> adj(N);
    
    for(auto &edge : edges) {
        int u = edge[0], v = edge[1];
        
        adj[u].push_back(v);
        if(!directed) 
            adj[v].push_back(u);
    }
    
    return adj;
}