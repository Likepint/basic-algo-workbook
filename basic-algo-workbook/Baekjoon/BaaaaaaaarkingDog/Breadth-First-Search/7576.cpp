#include <iostream>

#include <vector>
#include <queue>
using namespace std;

#define X first
#define Y second
#define endl '\n'

int width, height, zeroCnt, days = -1; // ����, ����, 0�� ����, �ɸ��� �Ⱓ
queue<pair<int, int>> q;
vector<pair<int, int>> direction = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} }; // ����

vector<vector<int>> Input() // �ڽ� ũ�� ����
{
	cin >> width >> height;

	vector<vector<int>> ret(height, vector<int>(width, 0));

	for (size_t i = 0; i < ret.size(); ++i)
	{
		for (size_t j = 0; j < ret[i].size(); ++j)
		{
			cin >> ret[i][j];

			if (ret[i][j] == 0) // 0�� ����
				zeroCnt++;

			if (ret[i][j] == 1) // 1�� ��ǥ
				q.push({ i, j });
		}
	}

	return ret;
}

void BFS(vector<vector<int>>& box)
{
	vector<vector<int>> visited = box;

	while (!q.empty())
	{
		days++;

		int size = q.size(); // �Ϸ縦 ����ϱ� ���� q ������

		while (size-- > 0)
		{
			int cx = q.front().X;
			int cy = q.front().Y;

			q.pop();

			for (int i = 0; i < direction.size(); ++i)
			{
				int nx = cx + direction[i].X;
				int ny = cy + direction[i].Y;

				if (0 > nx or nx >= height) continue;

				if (0 > ny or ny >= width) continue;

				if (visited[nx][ny] == 1) continue;

				if (box[nx][ny] != 0) continue;

				visited[nx][ny] = 1;

				box[nx][ny] = 1;

				zeroCnt--; // 0�� ���� ����

				q.push({ nx, ny });
			}
		}
	}
}

int main()
{
	vector<vector<int>> box = Input();

	BFS(box);

	if (zeroCnt != 0)
	{
		cout << -1 << endl;

		return 0;
	}
	
	cout << days << endl;

	return 0;
}