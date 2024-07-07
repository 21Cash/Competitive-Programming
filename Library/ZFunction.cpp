/*
zArr[i] = length of the longest substring starting from position i 
that matches the prefix of the given string.
*/
vector<int> z_function(const string &s) {
    int n = s.size();
    vector<int> z(n);
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            z[i] = min(z[i - l], r - i + 1);
        for (int &j = z[i]; i + j < n && s[j] == s[i + j]; j++);
        if (z[i] > r - i + 1)
            l = i, r = i + z[i] - 1;
    }
    return z;
}