vector<ll> get_prefix_sum(vector<ll> &nums) {
    int n = nums.size();
    vector<ll> pref(n+1);
    pref[0] = 0LL;
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + nums[i-1];
    }
    return pref;
}