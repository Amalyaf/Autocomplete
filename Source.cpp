#include"TrieNode.h"
#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "");
	string keys[] = { "dog", "free", "cat", "freedom","call", "camera", "cafe", "cinema", "room", "restoran", "red" };
	int n = sizeof(keys) / sizeof(keys[0]);
	TrieNode* root;
	root = getNewNode();
	for (int i = 0; i < n; i++)
	{
		insert(root, keys[i]);
	}

	cout << "Словарь: ";
	print(root);

	char c = 'y';
	string key;
	string result;
	int i = 0;
	while (c == 'y')
	{
		cout << "\nВведите часть слова:" << endl;
		cin >> key;
		autocomplete(root, key,result);
		int f = sizeof(result) / sizeof(result[0]);
		if (f > 1)
		{
			cout << "\nВ словаре есть следующие слова с введённым префиксом:" << endl;
			cout << result << endl;
		}
		if (f == 1)
		{
			cout << "\nВ словаре есть одно слово с введённым префиксом:" << endl;
			cout << result << endl;
		}
		cout << "\nХотите продолжить ввод?(y/n)" << endl;
		cin >> c;
	}
	
}