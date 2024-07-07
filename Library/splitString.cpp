vector<string> splitString(string &str, char sep) {
    stringstream ss(str);
    vector<string> words;
    string word = "";
    while(getline(ss, word, sep)) {
        if(word.size() > 0) words.push_back(word);
    }
    return words;
}