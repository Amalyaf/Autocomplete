#include"TrieNode.h"
#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "");
	string keys[] = { "dog", "free", "cat", "freedom","call", "camera", "cafe", "cinema", "room", "restoran", "red",
	"hello", "my", "friend", "i"};
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
	string sentences{}; //для вывода предложения
	while (c == 'y')
	{
		int count = 0;
		string result{};
		string word{};
		string* res = new string[n]{};
		cout << "\nВведите часть слова:" << endl;
		cin >> key;
		autocomplete(root, key,result);
		int f = result.size();

		// запись строки string в массив типа string для выбора необходимого слова по индексу
		for (int i = 0; i < f; i++)
		{

			if (result[i] != 32)
			{
				word += result[i];
			}

			else
			{
				res[count++] = word;
				word = {};
			}
		}

		if (count > 1)
		{
			cout << "\nВ словаре есть следующие слова с введённым префиксом:" << endl;
			for (int j = 0; j < count; j++)
			{
				cout << j + 1 << ": " << res[j] << endl;
			}
			int choice;
			cout << "\nУкажите номер слова, которое хотите выбрать:" << endl;
			cin >> choice;
			if (choice > count || choice <= 0)
			{
				cout << "Некорректный ввод!" << endl;
			}
			else
			{
				sentences += res[choice - 1];
				sentences += ' ';
			}
		}
		if (count == 1)
		{
			sentences += res[0];
			sentences += ' ';
			cout << "\nВ словаре есть одно слово с введённым префиксом:" << endl;
		}

		cout << endl << sentences << endl;
		cout << "\nХотите продолжить ввод?(y/n)" << endl;
		cin >> c;
	}
}