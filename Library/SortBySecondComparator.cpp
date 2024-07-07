// sort based on second values
struct compare_by_second {
    bool operator()(const std::pair<ll, ll>& a, const std::pair<ll, ll>& b) const {
        if (a.second != b.second) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
};