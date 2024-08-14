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

	cout << "�������: ";
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
		cout << "\n������� ����� �����:" << endl;
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
			cout << "\n� ������� ���� ��������� ����� � �������� ���������:" << endl;
			for (int j = 0; j < count; j++)
			{
				cout << res[j] << endl;
			}
		}
		if (count == 1)
		{
			cout << "\n� ������� ���� ���� ����� � �������� ���������:" << endl;
			cout << res[0] << endl;
		}
		cout << "\n������ ���������� ����?(y/n)" << endl;
		cin >> c;
	}
	
}