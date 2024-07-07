// Static Range OR Query Segment Tree
class SegmentTreeOR {
private:
    vector<int> tree;
    int n;

    void build(const vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }
        
        int mid = start + (end - start) / 2;
        build(nums, 2 * node + 1, start, mid);
        build(nums, 2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] | tree[2 * node + 2];
    }

    int query(int node, int start, int end, int l, int r) {
        if (start > r || end < l) {
            return 0;
        }
        
        if (start >= l && end <= r) {
            return tree[node];
        }
        
        int mid = start + (end - start) / 2;
        int left = query(2 * node + 1, start, mid, l, r);
        int right = query(2 * node + 2, mid + 1, end, l, r);
        return left | right;
    }

public:
    SegmentTreeOR(const vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        build(nums, 0, 0, n - 1);
    }
    
    // Returns OR Of Range [l...r]
    int queryRange(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};