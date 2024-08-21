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

TrieNode* getNewNode(void); // Возвращет новый узел с пустыми детьми
void insert(TrieNode*, std::string); // Вставляет ключ в дерево
bool search(TrieNode*, std::string); // Поиск ключа в дереве
bool isEmpty(TrieNode*); // проверяет пустоту дерева
TrieNode* remove(TrieNode*, std::string, int depth = 0); // Рекурсивная функция удаления ключа из дерева
void findMinPrefixes(TrieNode*, char[], int, std::string&); // Поиск минимального перфикса
void findMinPref(TrieNode* root); // Обёртка для findMinPrefixes
void print(TrieNode* root); // Обёртка для printInner
void printInner(TrieNode* root, char buf[], int ind, std::string& res); // Вывод дерева на экран
void autocomplete(TrieNode* root, std::string key,std::string& result); // Поиск слова в дереве по введенной части слова
void findWords(TrieNode* root,std::string key, std::string& result); 
void findWordInner(TrieNode* root, char buf[], int ind, std::string& res);