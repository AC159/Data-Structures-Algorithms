#include <iostream>

#include "Trie.h"


Trie::TrieNode::TrieNode()
{
    children = vector< TrieNode* >( 26, nullptr );
    isWord = false;
}

Trie::Trie() : root( new TrieNode() )
{}

/** Get top 3 (lexicographically minimum) words that start with this prefix in sorted order */
void Trie::searchHelper( TrieNode* node, const string& currentPrefix, vector< string >& words )
{
    if ( words.size() == 3 ) return;
    if ( node->isWord ) words.push_back( currentPrefix );

    for ( char c = 'a'; c <= 'z'; ++c )
    {
        if ( node->children[ c - 'a' ] != nullptr )
        {
            searchHelper( node->children[ c - 'a' ], currentPrefix + c, words );
        }
    }
}

void Trie::insert( const string& word )
{
    // the calling node of this function must be the root node of the trie!
    TrieNode* current = root;
    for ( char c : word )
    {
        if ( current->children[ c - 'a' ] == nullptr )
        {
            current->children[ c - 'a' ] = new TrieNode();
        }
        current = current->children[ c - 'a' ];
    }
    current->isWord = true;
}

vector< string > Trie::search( const string& prefix )
{
    // Given this prefix, we need to crawl to the right node before getting the suggestions
    TrieNode* node = root;
    for ( char c : prefix )
    {
        if ( node == nullptr ) break;
        else node = node->children[ c - 'a' ];
    }

    vector< string > suggestions;
    if ( node != nullptr ) searchHelper( node, prefix, suggestions );
    return suggestions;
}

void TrieMain()
{
    Trie* trie = new Trie();
    vector< string > words = { "mobile", "mouse", "moneypot", "monitor", "mousepad" };
    for ( string word : words ) trie->insert( word ); // populate the trie

    string searchWord = "mo";
    vector< string > topSuggestions = trie->search( searchWord );

    std::cout << "\nHere are the top 3 suggestions (in lexicographical order) for the search word: " << searchWord
              << std::endl;
    for ( const string& w : topSuggestions ) std::cout << w << std::endl;
}
