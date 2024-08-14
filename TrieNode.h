#pragma once
#include <string>


const int ALPHABET_SIZE = 26;

// Структура узела дерева 
struct TrieNode
{
    TrieNode* children[ALPHABET_SIZE];
    // isEndOfWord - true, если ключ является концом слова
    bool isEndOfWord;
    int count = 0;
};

TrieNode* getNewNode(void);
void insert(TrieNode*, std::string);
bool search(TrieNode*, std::string);
bool isEmpty(TrieNode*);
TrieNode* remove(TrieNode*, std::string, int depth = 0);
void findMinPrefixes(TrieNode*, char[], int, std::string&);
void findMinPref(TrieNode* root);
void print(TrieNode* root);
void printInner(TrieNode* root, char buf[], int ind, std::string& res);
void autocomplete(TrieNode* root, std::string key,std::string& result);
void printWords(TrieNode* root,std::string key, std::string& result);
void printWordInner(TrieNode* root, char buf[], int ind, std::string& res);