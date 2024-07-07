vector<long long> getPref(vector<int> &nums) {
    int n = nums.size();
    vector<long long> pref(n+1, 0);
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + nums[i-1];
    }
    return pref;
}