#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Each node in the Trie represents a single character
struct TrieNode {
    TrieNode* children[26]; // Pointers to child nodes for 'a'-'z'
    bool isEndOfWord;       // True if the node represents the end of a word

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the Trie
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a'; // Convert character to index 0-25
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }

    // Returns true if the word is in the Trie
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) return false;
            curr = curr->children[index];
        }
        return curr->isEndOfWord;
    }

    // Returns true if there is any word that starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) return false;
            curr = curr->children[index];
        }
        return true;
    }
};

int main() {
    Trie* trie = new Trie();
    trie->insert("apple");
    cout << "Search 'apple': " << (trie->search("apple") ? "True" : "False") << endl; // True
    cout << "Search 'app': " << (trie->search("app") ? "True" : "False") << endl;     // False
    cout << "Starts with 'app': " << (trie->startsWith("app") ? "True" : "False") << endl; // True
    return 0;
}
