vector<int> prevSmallerInd(vector<int> &nums) {
    int N = nums.size();
    vector<int> res(N);
    stack<int> st;
    for(int i = 0; i < N; i++) {
        while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
        if(st.empty()) res[i] = -1;
        else res[i] = st.top();
        st.push(i); 
    }
    return res;
}