#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include<cstring>
#include<stack>
#include<string.h>
#include<stdio.h>

using namespace std;

int n, m, t;
int board[102][102];
int visit[102][102][2];
int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,-1,1 };


typedef struct {
	int x;
	int y;
	int dist;
	int sword;
}Info;

int bfs() {

	queue<Info> q;
	q.push({ 0,0,0,0 });
	visit[0][0][0] = 1;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dist = q.front().dist;
		int sword = q.front().sword;
		q.pop();

		if (board[x][y] == 2) sword = 1;
		if (x == n - 1 && y == m - 1)return dist;
		
		for (int i = 0; i < 4; i++) {		
			int c_x = x + xx[i];
			int c_y = y + yy[i];
			if (c_x < 0 || c_y < 0 || c_x >= n || c_y >= m || visit[c_x][c_y][sword] == 1 || dist + 1>t)continue;
			if (board[c_x][c_y] == 1 && sword == 0)continue;

			q.push({ c_x,c_y,dist + 1,sword });
			visit[c_x][c_y][sword] = 1;
		}
	}
	return 0;

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int answer;
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	answer = bfs();
	if (answer == 0) {
		cout << "Fail";
	}
	else {
		cout << answer;
	}
}