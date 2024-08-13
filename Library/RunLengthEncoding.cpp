vector<pair<char, int>> run_length_encoding(string &str) {
    if (str.empty()) return {};

    vector<pair<char, int>> result;
    char current_char = str[0];
    int count = 1;

    for (int i = 1; i < str.size(); ++i) {
        if (str[i] == current_char) {
            ++count;
        } else {
            result.emplace_back(current_char, count);
            current_char = str[i];
            count = 1;
        }
    }
    
    // For the last group
    result.emplace_back(current_char, count); 
    return result;
}