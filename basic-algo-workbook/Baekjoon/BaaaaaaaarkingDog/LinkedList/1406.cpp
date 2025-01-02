#include <iostream>
#include <list>
#include <string>

using namespace std;

#define endl '\n'

list<char> Set()
{
	list<char> editor;

	string sentence = "";
	cin >> sentence;

	for (const auto& ch : sentence)
		editor.emplace_back(ch);

	return editor;
}

bool IsPCommand(char InCommand)
{
	return InCommand == 'P' ? true : false;
}

void ExcuteEtcCommand(list<char>& Editor, const char& InCommand, list<char>::iterator& InCursor)
{
	switch (InCommand)
	{
		case 'L':
		{
			if (InCursor != Editor.begin())
				InCursor--;

			break;
		} // case L

		case 'D':
		{
			if (InCursor != Editor.end())
				InCursor++;

			break;
		} // case D

		case 'B':
		{
			if (InCursor != Editor.begin())
				InCursor = Editor.erase(--InCursor);
			// ���� ( list return value )
			// https://learn.microsoft.com/ko-kr/cpp/standard-library/list-class?view=msvc-170

			break;
		} // case B
	}
}

void ExcuteCommand(list<char>& Editor)
{
	auto cursor = Editor.end(); // Ŀ�� ��ġ ����

	size_t times = 0;
	cin >> times;

	char command, ch;

	for (size_t i = 0; i < times; ++i)
	{
		cin >> command;

		if (IsPCommand(command))
		{
			cin >> ch;

			Editor.insert(cursor, ch);

			continue;
		}

		ExcuteEtcCommand(Editor, command, cursor);
	}
}

int main()
{
	list<char> editor = Set();

	ExcuteCommand(editor);

	for (const auto& ch : editor)
		cout << ch;

	cout << endl;

	return 0;
}