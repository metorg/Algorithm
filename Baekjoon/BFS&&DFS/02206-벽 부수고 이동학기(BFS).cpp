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
int n, m;
char board[1005][1005];
int visit[1000][1000][2];
int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,-1,1 };
int mst = 2e9;
vector<pair<int, int>> wall;
void bfs() {
	int cnt = 1;
	int brk = 0;
	if (board[0][0] == '1') {
		brk = 1;
	}
	queue<pair<pair<int, int>, pair<int, int>>> q;

	q.push({ { 0,0 }, {cnt,brk} });
	visit[0][0][brk] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int k = q.front().second.first;
		int p = q.front().second.second;
		q.pop();


		if (x == n - 1 && y == m - 1) {

			if (mst > k) {
				mst = k;
			}
			break;
		}
		for (int i = 0;i < 4;i++) {
			int c_x = xx[i] + x;
			int c_y = yy[i] + y;
			if (c_x < 0 || c_y < 0 || c_x >= n || c_y >= m || visit[c_x][c_y][p] == 1 || board[c_x][c_y] == '1') {

				if (board[c_x][c_y] == '1' && p == 0) {
					q.push({ {c_x,c_y},{k + 1,1} });
				}

				continue;
			}
			q.push({ { c_x,c_y }, {k + 1 ,p} });
			visit[c_x][c_y][p] = 1;

		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> board[i][j];
			if (board[i][j] == '1') {
				wall.push_back({ i,j });
			}
		}
	}

	bfs();
	if (mst == 2e9) {
		cout << -1;
	}
	else
		cout << mst;
}
