#include "TrieNode.h"
#include <iostream>
using namespace std;

// ��������� ����� ���� � ������� ������
TrieNode* getNewNode(void)
{
    // �������� ������ �� ����� ����
    struct TrieNode* pNode = new TrieNode;

    // ������������� ���� ����� ����� � false
    pNode->isEndOfWord = false;

    // �������������� ����� ������� ���������
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}


// ��������� ���� � ������, ���� ��� ���, 
// ����� ���� ���� ������� �������� ���� ������ 
// �������� ��������� �������� �.�. ����� �����
void insert(TrieNode* root, string key)
{
    TrieNode* node = root;
    
    for (int i = 0; i < key.length(); i++)
    {
        // ��������� ������ � �������� ����� �������� ������������ ������ �����
        int index = key[i] - 'a';
        // ���� ��������� ������, �.�. ����� � ����� ��������� ���
        // ������� ����� ����
        if (!node->children[index])
            node->children[index] = getNewNode();

        node = node->children[index];
        node->count++;
    }

    // �������� ��������� ����� ��� ����, �.�. ����� �����
    node->isEndOfWord = true;
}

// ���������� true ���� ���� ���� � ������, ����� false 
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

// ���������� true ���� root ����� ����, ����� false 
bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}

// ����������� ������� �������� ����� �� ������ 
TrieNode* remove(TrieNode* root, string key, int depth)
{
    // ���� ������ ������ 
    if (!root)
        return nullptr;

    // ���� ����� �� ����� ����� 
    if (depth == key.size()) {

        // ���� ���� ������ �� ����� ����� 
        if (root->isEndOfWord)
            root->isEndOfWord = false;

        // ���� ���� �� �������� ���������, ������� ���
        if (isEmpty(root)) {
            delete (root);
            root = nullptr;
        }

        return root;
    }

    // ���� �� ����� �� ����� �����, ���������� �������� ��� ������� 
    // ���������������� ������� 
    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index], key, depth + 1);

    // ���� � ����� ��� ��������� ����� 
    // (������ ������ ���� ��� �������� �������), 
    // � �� �� ������������� ������ ������. 
    if (isEmpty(root) && root->isEndOfWord == false) {
        delete (root);
        root = nullptr;
    }

    // ���������� ����� ������
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
// �� ���������� ��������� �������
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
   // ���� ������� ���� �������� ������ �����(root->isEndOfWord), �� ��������� ������ ��������� ������ � �����, 
   // ����� ��������� ����� � ��������� res � ��������� ������.
   //�������� �� ���� ��������� ����� ����
   // ���� ���� �� ������, ��������� ��������������� ������ � ����� � ���������� �������� printInnet ��� 
    //���������� ������ ������
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
            std::cout << "����� �� �������" << std::endl;
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