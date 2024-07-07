int lengthOfLIS(vector<int>& nums) {
    int N = nums.size();
    vector<int> buf;
    for(int x : nums) {
        auto ind = lower_bound(buf.begin(), buf.end(), x) - buf.begin();
        if(ind >= buf.size()) buf.push_back(x);
        else buf[ind] = x;
    }
    return buf.size();
}