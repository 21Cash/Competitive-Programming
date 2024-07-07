vector<vector<int>> getSubarrays(vector<int> &nums) {
    vector<vector<int>> subarrays;
    int N = nums.size();
    for(int i = 0; i < N; i++) {
        vector<int> cur;
        for(int j = i ; j < N; j++) {
            cur.push_back(nums[j]);
            subarrays.push_back(cur);
        }
    }
    
    return subarrays;
}