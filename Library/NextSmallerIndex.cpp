vector<int> nextSmallerInd(vector<int> &nums) {
    int N = nums.size();
    stack<int> st;
    vector<int> res(N);
    for(int i = N-1; i >= 0; i--) {
        while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
        if(st.empty()) res[i] = -1;
        else res[i] = st.top();
        st.push(i);
    }
    return res;
}