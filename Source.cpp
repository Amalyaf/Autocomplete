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

	cout << "�������: ";
	print(root);

	char c = 'y';
	string key;
	string sentences{}; //��� ������ �����������
	while (c == 'y')
	{
		int count = 0;
		string result{};
		string word{};
		string* res = new string[n]{};
		cout << "\n������� ����� �����:" << endl;
		cin >> key;
		autocomplete(root, key,result);
		int f = result.size();

		// ������ ������ string � ������ ���� string ��� ������ ������������ ����� �� �������
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
			cout << "\n� ������� ���� ��������� ����� � �������� ���������:" << endl;
			for (int j = 0; j < count; j++)
			{
				cout << j + 1 << ": " << res[j] << endl;
			}
			int choice;
			cout << "\n������� ����� �����, ������� ������ �������:" << endl;
			cin >> choice;
			if (choice > count || choice <= 0)
			{
				cout << "������������ ����!" << endl;
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
			cout << "\n� ������� ���� ���� ����� � �������� ���������:" << endl;
		}

		cout << endl << sentences << endl;
		cout << "\n������ ���������� ����?(y/n)" << endl;
		cin >> c;
	}
}