vector<pair<int, int>> merge_intervals(vector<pair<int, int>> intervals) {
    sort(intervals.begin(), intervals.end());

    auto [prevStart, prevEnd] = intervals[0];
    int N = intervals.size();

    vector<pair<int, int>> res;
    
    for(int i = 1; i < N; i++) {
        auto [currentStart, currentEnd] = intervals[i];

        if(currentStart >= prevStart && currentStart <= prevEnd) {
            prevEnd = max(currentEnd, prevEnd);
        }
        else {
            res.push_back({prevStart, prevEnd});
            prevStart = currentStart;
            prevEnd = currentEnd;
        }
    }

    res.push_back({prevStart, prevEnd});
    return res;
}