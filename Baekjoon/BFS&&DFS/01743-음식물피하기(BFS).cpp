#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stack>
#include<memory.h>
#include<unordered_map>
using namespace std;
vector<pair<int, int>> trash;
char board[101][101];
int n, m, trash_num;
int visit[101][101];
int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,1,-1 };
int mcnt = 0;
void bfs(int i, int j) {
	int cnt = 1;
	queue<pair<int, int>> q;
	q.push({ i,j });
	visit[i][j] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();
		for (int i = 0;i < 4;i++) {
			int c_x = x + xx[i];
			int c_y = y + yy[i];
			if (c_x < 0 || c_y < 0 || c_x >= n || c_y >= m || (board[c_x][c_y] == '.') || (visit[c_x][c_y] == 1)) {
				continue;
			}
			visit[c_x][c_y] = 1;
			q.push({ c_x,c_y });
			cnt++;
			if (cnt > mcnt) {
				mcnt = cnt;
			}


		}
	}

}
int main() {
	cin >> n >> m >> trash_num;
	int a, b;
	for (int i = 0;i < trash_num;i++) {
		cin >> a >> b;
		board[a - 1][b - 1] = '#';
		trash.push_back({ a - 1,b - 1 });
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (board[i][j] != '#') {
				board[i][j] = '.';
			}
		}
	}

	for (int i = 0;i < trash.size();i++) {
		if (!visit[trash[i].first][trash[i].second]) {
			bfs(trash[i].first, trash[i].second);
		}
	}

	cout << mcnt;

}
