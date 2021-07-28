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

typedef struct {
	int x;
	int y;
	int dist;
}info;

int n, m;
int board[1001][1001];
int h, w, s1, s2, f1, f2;
int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,1,-1 };
int visit[1001][1001];

int bfs() {
	queue<info> q;
	q.push({ s1 - 1,s2 - 1,0 });
	visit[s1 - 1][s2 - 1] = 1;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dist = q.front().dist;
		q.pop();
		if (x == f1-1 && y == f2-1)return dist;

		for (int i = 0; i < 4; i++) {
			int c_x = x + xx[i];
			int c_y = y + yy[i];
			int cut = 0;
			
			if (c_x < 0 || c_y < 0 || c_x + h - 1 >= n || c_y + w - 1 >= m || visit[c_x][c_y] == 1||board[c_x][c_y]==1)continue;
			for (int j = 0; j < w; j++) {				
				if (board[c_x + h - 1][c_y + j] == 1||board[c_x][c_y+j]==1) {
					cut++;
					break;
				}
			}
			for (int j = 0; j < h; j++) {
				if (board[c_x + j][c_y + w - 1] == 1||board[c_x+j][c_y]==1) {
					cut++;
					break;
				}
			}
			
			if (cut != 0)continue;
			q.push({ c_x,c_y,dist+1 });
			visit[c_x][c_y] = 1;
		}

	}
	return -1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	cin >> h >> w >> s1 >> s2 >> f1 >> f2;
	cout << bfs();

}