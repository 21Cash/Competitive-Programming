// ------------------------ AND Segment Tree (Range Query and Point Update) -------------------

class SegmentTree {
private:
    vector<int> tree;
    int n;

    void buildTree(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            buildTree(arr, 2 * node + 1, start, mid);
            buildTree(arr, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] & tree[2 * node + 2];
        }
    }

    int rangeAnd(int node, int start, int end, int L, int R) {
        if (R < start || end < L) {
            return INT_MAX;
        }
        if (L <= start && end <= R) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftAnd = rangeAnd(2 * node + 1, start, mid, L, R);
        int rightAnd = rangeAnd(2 * node + 2, mid + 1, end, L, R);
        return leftAnd & rightAnd;
    }

    void updateTree(int node, int start, int end, int idx, int value) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                updateTree(2 * node + 1, start, mid, idx, value);
            } else {
                updateTree(2 * node + 2, mid + 1, end, idx, value);
            }
            tree[node] = tree[2 * node + 1] & tree[2 * node + 2];
        }
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        buildTree(arr, 0, 0, n - 1);
    }

    int rangeAnd(int L, int R) {
        return rangeAnd(0, 0, n - 1, L, R);
    }

    void update(int idx, int value) {
        updateTree(0, 0, n - 1, idx, value);
    }
};

// -----------------------------------------------------------------------------------