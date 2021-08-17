#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct {
	int x;
	int y;
	int dist;
	int chance;
}info;

int h_xx[8] = { -2,-1,-2,-1,1,2,1,2 };
int h_yy[8] = { -1,-2,1,2,-2,-1,2,1 };
int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,-1,1 };
int k, n, m;
int board[201][201];
int visit[31][201][201];

int bfs() {
	queue<info> q;
	q.push({ 0,0,0,k });
	visit[k][0][0] = 1;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dist = q.front().dist;
		int chance = q.front().chance;
		q.pop();
		if (x == m - 1 && y == n - 1)return dist;
		for (int i = 0; i < 8; i++) {
			if (chance < 1)break;
			int c_chance = chance - 1;
			int c_x = x + h_xx[i];
			int c_y = y + h_yy[i];
			if (c_x < 0 || c_y < 0 || c_x >= m || c_y >= n || visit[c_chance][c_x][c_y] == 1 || board[c_x][c_y] == 1)continue;
			q.push({ c_x,c_y,dist + 1,c_chance });
			visit[c_chance][c_x][c_y] = 1;
		}
		for (int i = 0; i < 4; i++) {
			int c_x = x + xx[i];
			int c_y = y + yy[i];
			if (c_x < 0 || c_y < 0 || c_x >= m || c_y >= n || visit[chance][c_x][c_y] == 1 || board[c_x][c_y] == 1)continue;
			q.push({ c_x,c_y,dist + 1,chance });
			visit[chance][c_x][c_y] = 1;
		}
	}
	return -1;
}

int main() {
	cin >> k >> n >> m;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	cout << bfs();
}

