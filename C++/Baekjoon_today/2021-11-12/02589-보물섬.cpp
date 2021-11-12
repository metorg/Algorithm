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

typedef struct info {
	int x;
	int y;
	int dist;
};

int n, m;
int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,-1,1 };
int answer = 0;
char board[51][51];
int visit[51][51];

vector<pair<int, int>> land;


void bfs(int i, int j) {
	queue<info> q;
	q.push({ i,j,0 });
	visit[i][j] = 1;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dist = q.front().dist;
		q.pop();
		answer = max(answer, dist);
		for (int i = 0; i < 4; i++) {
			int c_x = x + xx[i];
			int c_y = y + yy[i];
			if (c_x < 0 || c_y < 0 || c_x >= n || c_y >= m || board[c_x][c_y] == 'W' || visit[c_x][c_y])continue;
			q.push({ c_x,c_y,dist + 1 });
			visit[c_x][c_y] = 1;
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'L') {
				land.push_back({ i,j });
			}
		}
	}
	for (int i = 0; i < land.size(); i++) {
		bfs(land[i].first, land[i].second);
		memset(visit, 0, sizeof(visit));
	}
	cout << answer;


}