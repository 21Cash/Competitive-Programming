class TrieNode {
private:
    TrieNode* childs[26];
public: 
    bool terminal = false;
    int frequency = 0;

    TrieNode() {
        for(int child = 0; child < 26; child++) {
            childs[child] = nullptr;
        }
        terminal = false;
    }  
    
    TrieNode* getChild(char ch) {
        return childs[ch - 'a'];
    }
    
    void putChild(char ch, TrieNode* childNode) {
        childs[ch - 'a'] = childNode;
    }
};

class Trie {
public: 
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insertWord(string &word) {
        TrieNode* cur_node = root;
        int N = word.size();
        for(int i = 0; i < N; i++) {
            TrieNode* next = cur_node->getChild(word[i]);
            if(!next) {
                next = new TrieNode();
            }
            
            cur_node->putChild(word[i], next);
            cur_node = cur_node->getChild(word[i]);
        }
        
        cur_node->terminal = true;
        cur_node->frequency++;
    }
};