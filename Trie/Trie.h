#ifndef ALGORITHMS_TRIE_H
#define ALGORITHMS_TRIE_H

#include <vector>
#include <string>

using std::vector;
using std::string;

class Trie
{
private:
    class TrieNode
    {
     public:
        vector< TrieNode* > children;
        bool isWord;

        TrieNode();
    };

    TrieNode* root;

    void searchHelper( TrieNode* node, const string& currentPrefix, vector< string >& words );

public:
    Trie();

    void insert( const string& word );
    vector< string > search( const string& prefix );
};

void TrieMain();

#endif //ALGORITHMS_TRIE_H
