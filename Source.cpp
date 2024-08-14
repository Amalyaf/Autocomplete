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
	
	
	
	
	while (c == 'y')
	{
		int j = 0;
		int count = 0;
		string result{};
		string word{};
		string* res = new string[n]{};
		cout << "\nВведите часть слова:" << endl;
		cin >> key;
		autocomplete(root, key,result);
		int f = result.size();

		for (int i = 0; i < f; i++)
		{

			if (result[i] != 32)
			{
				word += result[i];
			}

			else
			{
				res[j++] = word;
				count++;
				word = {};
			}
		}

		if (count > 1)
		{
			cout << "\nВ словаре есть следующие слова с введённым префиксом:" << endl;
			for (int j = 0; j < count; j++)
			{
				cout << res[j] << endl;
			}
		}
		if (count == 1)
		{
			cout << "\nВ словаре есть одно слово с введённым префиксом:" << endl;
			cout << res[0] << endl;
		}
		cout << "\nХотите продолжить ввод?(y/n)" << endl;
		cin >> c;
	}
	
}