class XorTrie {
    struct Node {
        Node* links[2];
        int frequency; 
        Node() : frequency(0) {
            links[0] = links[1] = nullptr;
        }

        bool containsKey(int bit) {
            return (links[bit] != nullptr);
        }

        Node* get(int bit) {
            return links[bit];
        }

        void put(int bit, Node* node) {
            links[bit] = node;
        }
    };
private:
    Node* root;
public:
    // Constructor: Initializes the Trie with a root node.
    XorTrie() {
        root = new Node();
    }

    // Inserts the number into the Trie.
    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
            node->frequency++;
        }
    }
    
    // Deletes given number from the Trie.
    void del(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(bit)) {
                node = node->get(bit);
                node->frequency--;
            } else {
                break;
            }
        }
    }

    // Finds the best matching binary number that maximizes XOR with the given number.
    // returns value 'x' such that (num XOR x) is as maximum as possible.
    int getBest(int num) {
        Node* node = root;
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit) && node->get(1 - bit)->frequency > 0) {
                res = res | (1 << i);
                node = node->get(1 - bit);
            } else {
                if(node->containsKey(bit) && node->get(bit)->frequency > 0) node = node->get(bit);
                else return 0;
            }
        }
        return res;
    }
};