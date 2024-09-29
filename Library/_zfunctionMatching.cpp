// Z[i] = prefix match length for pattern from source[i]
vector<int> z_function(const string &source, const string &pattern) {
    string s = pattern + '#' + source;
    int n = s.size(), m = pattern.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return vector<int>(z.begin() + m + 1, z.end());
}