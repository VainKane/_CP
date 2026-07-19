#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    string word;

    TrieNode() {
        isEnd = false;
        word = "";
        memset(children, 0, sizeof(children));
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isEnd = true;
        node->word = word;
    }

    string findLongestWord(unordered_map<char, int>& freq) {
        string longest = "";
        dfs(root, freq, longest);
        return longest.empty() ? "IMPOSSIBLE" : longest;
    }

private:
    void dfs(TrieNode* node, unordered_map<char, int>& freq, string& longest) {
        if (node->isEnd) {
            if (node->word.length() > longest.length() || 
                (node->word.length() == longest.length() && node->word < longest)) {
                longest = node->word;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (node->children[i] && freq['a' + i] > 0) {
                freq['a' + i]--;
                dfs(node->children[i], freq, longest);
                freq['a' + i]++;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("15F.inp", "r", stdin);
    freopen("15F.ans", "w", stdout);
    
    int n, t;
    cin >> n;
    
    Trie trie;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        trie.insert(word);
    }

    cin >> t;
    vector<string> results;
    for (int i = 0; i < t; i++) {
        string letters;
        cin >> letters;
        
        unordered_map<char, int> freq;
        for (char c : letters) freq[c]++;

        results.push_back(trie.findLongestWord(freq));
    }

    for (const string& res : results) {
        cout << res << '\n';
    }

    return 0;
}
