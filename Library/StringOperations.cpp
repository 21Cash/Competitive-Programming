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
        
        ll query_freq(int left, int right, char ch) {
            return prefix[right + 1][ord(ch)] - prefix[left][ord(ch)];        
        }
        
        vector<ll> get_table(int left, int right) {
            vector<ll> table = prefix[right + 1];
            for(int curId = ord(baseChar); curId <= ord(endChar); curId++) {
                table[curId] -= prefix[left][curId];
            }
            return table;
        }
    };
    
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
    
    vector<string> split_string(string &str, char sep) {
        stringstream ss(str);
        vector<string> words;
        string word = "";
        while(getline(ss, word, sep)) {
            if(word.size() > 0) words.push_back(word);
        }
        return words;
    }
    
    ll binary_to_long_long(string &binaryString) {
        ll result = 0;
        for (char bit : binaryString) {
            result = (result << 1) + (bit - '0');  
        }
        return result;
    }
    
     // Returns binary string with removing leading zeroes
    string get_binary_string(ll n) {
        if (n == 0) return "0";  

        string binary;
        for (int i = sizeof(ll) * 8 - 1; i >= 0; --i) {
            binary += (n & (1LL << i)) ? '1' : '0';
        }

        return binary.substr(binary.find('1'));
    }
    
        
    string trim_left(const string &s, char trimChar) {
        size_t start = 0;
        while (start < s.size() && s[start] == trimChar) {
            start++;
        }
        return s.substr(start); 
    }

    string trim_right(const string &s, char trimChar) {
        size_t end = s.size();
        while (end > 0 && s[end - 1] == trimChar) {
            end--;
        }
        return s.substr(0, end); 
    }
}

using namespace stringOperations;