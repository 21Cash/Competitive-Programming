#pragma region LCA_Query

// O(LogN) LCA Queries
// Give 0 - Based Edges

class LCA_Query {
public:
    LCA_Query(const std::vector<std::vector<int>>& edges) {
        int n = edges.size() + 1;
        LOG = 0;
        while ((1 << LOG) <= n) ++LOG;
        
        parent.assign(n, std::vector<int>(LOG, -1));
        depth.assign(n, 0);
        adj.assign(n, std::vector<int>());
        
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        dfs(0, -1);
        preprocess();
    }

    int get_lca(int x, int y) {
        if (depth[x] < depth[y]) std::swap(x, y);
        
        int diff = depth[x] - depth[y];
        for (int i = 0; i < LOG; ++i) {
            if (diff & (1 << i)) x = parent[x][i];
        }
        
        if (x == y) return x;
        
        for (int i = LOG - 1; i >= 0; --i) {
            if (parent[x][i] != parent[y][i]) {
                x = parent[x][i];
                y = parent[y][i];
            }
        }
        
        return parent[x][0];
    }

private:
    std::vector<std::vector<int>> parent;
    std::vector<int> depth;
    std::vector<std::vector<int>> adj;
    int LOG;

    void dfs(int v, int p) {
        parent[v][0] = p;
        for (int u : adj[v]) {
            if (u == p) continue;
            depth[u] = depth[v] + 1;
            dfs(u, v);
        }
    }

    void preprocess() {
        for (int j = 1; j < LOG; ++j) {
            for (int i = 0; i < parent.size(); ++i) {
                if (parent[i][j - 1] != -1) {
                    parent[i][j] = parent[parent[i][j - 1]][j - 1];
                }
            }
        }
    }
};

#pragma endregion