#include "TrieNode.h"
#include <iostream>
using namespace std;

// Возвращет новый узел с пустыми детьми
TrieNode* getNewNode(void)
{
    // Выделяем память по новый узел
    struct TrieNode* pNode = new TrieNode;

    // устанавливаем флаг конца слова в false
    pNode->isEndOfWord = false;

    // инициализируем детей нулевым уазателем
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}


// Вставляет ключ в дерево, если его нет, 
// иначе если ключ явлется префксом узла дерева 
// помечает вкачестве литового т.е. конец слова
void insert(TrieNode* root, string key)
{
    TrieNode* node = root;
    
    for (int i = 0; i < key.length(); i++)
    {
        // вычисляем индекс в алфавите через смещение относительно первой буквы
        int index = key[i] - 'a';
        // если указатель пустой, т.е. детей с таким префиксом нет
        // создаем новый узел
        if (!node->children[index])
            node->children[index] = getNewNode();

        node = node->children[index];
        node->count++;
    }

    // помечаем последний узлел как лист, т.е. конец слова
    node->isEndOfWord = true;
}

// Возврашает true если ключ есть в дереве, иначе false 
bool search(TrieNode* root, string key)
{
    TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!node->children[index])
            return false;

        node = node->children[index];
    }

    return (node != nullptr && node->isEndOfWord);
}

// Вохвращает true если root имеет лист, иначе false 
bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}

// Рекурсивная функция удаления ключа из дерева 
TrieNode* remove(TrieNode* root, string key, int depth)
{
    // Если дерево пустое 
    if (!root)
        return nullptr;

    // если дошли до конца ключа 
    if (depth == key.size()) {

        // Этот узел больше не конец слова 
        if (root->isEndOfWord)
            root->isEndOfWord = false;

        // Если ключ не евляется префиксом, удаляем его
        if (isEmpty(root)) {
            delete (root);
            root = nullptr;
        }

        return root;
    }

    // Если не дошли до конца ключа, рекурсивно вызываем для ребенка 
    // соответствующего символа 
    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index], key, depth + 1);

    // Если у корня нет дочернего слова 
    // (удален только один его дочерний элемент), 
    // и он не заканчивается другим словом. 
    if (isEmpty(root) && root->isEndOfWord == false) {
        delete (root);
        root = nullptr;
    }

    // возвращаем новый корень
    return root;
}

void findMinPref(TrieNode* root)
{
    TrieNode* node = root;
    char buf[ALPHABET_SIZE];
    string res;
    int index = 0;
    findMinPrefixes(root, buf, index, res);
}
// не изменияйте сигнатуру функции
void findMinPrefixes(TrieNode* root, char buf[], int ind, string& res)
{
    if (root == nullptr)
        return;

    if (root->count == 1)
    {
        res += buf;
        res += ' ';
    std:cout << res << std::endl;
        return;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->children[i])
        {
            buf[ind] = 'a' + i;
            buf[ind + 1] = '\0';
            findMinPrefixes(root->children[i], buf, ind + 1, res);
        }
    }
}
void print(TrieNode* root)
{
    TrieNode* node = root;
    char buf[ALPHABET_SIZE];
    string res;
    int index = 0;
    printInner(root, buf, index, res);
    cout << res << endl;

}
void printInner(TrieNode* root, char buf[],int ind, string& res)
{
   // Если текущий узел является концом слова(root->isEndOfWord), мы добавляем символ окончания строки в буфер, 
   // затем добавляем слово в результат res и добавляем пробел.
   //Проходим по всем возможным детям узла
   // Если узел не пустой, добавляем соответствующий символ в буфер и рекурсивно вызываем printInnet для 
    //следующего уровня дерева
   if (!root)
        return;

  if (root->isEndOfWord)
    {
        buf[ind] = '\0';
        res += buf;
        res += ' ';
        return;
    }
 
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->children[i] != nullptr)
        {
            buf[ind] = i + 'a';
            buf[ind + 1] = '\0';
            printInner(root->children[i], buf, ind+1, res);
        }
    }
}

void autocomplete(TrieNode* root, string key, string& result)
{
    result = {};
    TrieNode* node = root;
    int i = 0;
    int index;
    for (i = 0; i < key.size(); i++)
    {
        index = key[i] - 'a';
        if (!node->children[index])
        {
            std::cout << "Слово не найдено" << std::endl;
            break;
        }
        node = node->children[index];
    }
    if (i == key.size())
    {
        printWords(root,key,result);
    }
}

void printWords(TrieNode* root, string key, string& result)
{
    TrieNode* node = root;
    char buf[26];
    int j = 0;
    for (int i = 0; i < key.size(); i++)
    {
        int index = key[i] - 'a';
        if (node->children[index])
        {
            buf[j++] = index + 'a';
            node = node->children[index];
        }
    }

    printWordInner(node, buf, j, result);
    //std::cout << result << endl;
}

void printWordInner(TrieNode* root, char buf[], int ind, string& result)
{
    if (!root)
    {
        return;
    }
      

    if (root->isEndOfWord)
    {
        buf[ind] = '\0';
        result += buf;
        result += ' ';
        
        return;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->children[i] != nullptr)
        {
            buf[ind] = i + 'a';
            buf[ind + 1] = '\0';
            printWordInner(root->children[i], buf, ind + 1, result);
        }
    }
}