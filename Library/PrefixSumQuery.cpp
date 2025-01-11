class PrefixSumQuery {
private:
    vector<ll> prefix_sum;
public:
    PrefixSumQuery(vector<int> &nums) {
        int N = nums.size();
        prefix_sum.resize(N + 1);
        prefix_sum[0] = 0;
        
        for(int i = 1; i <= N; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
        }
    }
    
    ll query_sum(int left, int right) {
        assert(left <= right);
        return prefix_sum[right + 1] - prefix_sum[left];
    }
};