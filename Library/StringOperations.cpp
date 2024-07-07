namespace stringOperations {
    struct stringQuery {
        vector<vector<ll>> prefix; 
        char baseChar = 'a', endChar = 'z';
        
        int ord(char ch) {
            return ch - baseChar;
        }
        
        char getCharByOrd(int order) {
            return baseChar + order;
        }       
        
        void init(string &str) {
            int N = str.size();
            int alphabetSize = endChar - baseChar + 1;
            prefix.resize(N + 1, vector<ll> (alphabetSize, 0LL));
            
            for(int i = 1; i <= N; i++) {
                for(int curId = ord(baseChar); curId <= ord(endChar); curId++) {
                    prefix[i][curId] = prefix[i - 1][curId] + (str[i - 1] == getCharByOrd(curId));
                }
            }
        }
        
        stringQuery(string &str) {
            init(str);
        }
		
        stringQuery(string &str, char _baseChar, char _endChar) {
            baseChar = _baseChar, endChar = _endChar;
            init(str);
        }
        
        ll queryFreq(int left, int right, char ch) {
            return prefix[right + 1][ord(ch)] - prefix[left][ord(ch)];        
        }
        
        vector<ll> getTable(int left, int right) {
            vector<ll> table = prefix[right + 1];
            for(int curId = ord(baseChar); curId <= ord(endChar); curId++) {
                table[curId] -= prefix[left][curId];
            }
            return table;
        }
    };
    
    vector<string> splitString(string &str, char sep) {
        stringstream ss(str);
        vector<string> words;
        string word = "";
        while(getline(ss, word, sep)) {
            if(word.size() > 0) words.push_back(word);
        }
        return words;
    }
}

using namespace stringOperations;