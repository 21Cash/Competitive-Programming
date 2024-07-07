// KMP
vector<int> getOccIndices(const string& source, const string& pattern) {
    auto calculateLPS = [](const string& pattern) {
        int m = pattern.size();
        vector<int> lps(m, 0);

        int len = 0;
        int i = 1;

        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    };

    vector<int> result;

    int n = source.size();
    int m = pattern.size();

    vector<int> lps = calculateLPS(pattern);

    int i = 0; // index for source
    int j = 0; // index for pattern

    while (i < n) {
        if (pattern[j] == source[i]) {
            i++;
            j++;
        }

        if (j == m) {
            result.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != source[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return result;
}