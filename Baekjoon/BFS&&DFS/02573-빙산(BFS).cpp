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
int board[300][300];
int visit[300][300];
int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,-1,1 };
int ccnt;
int ice;
int last;
int col, row;
void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	ice++;
	last = 0;
	visit[i][j] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();
		int wall = 0;
		for (int i = 0;i < 4;i++) {

			int x_c = x + xx[i];
			int y_c = y + yy[i];
			if (x_c < 0 || y_c < 0 || x_c >= n || y_c >= m || visit[x_c][y_c] == 1 || board[x_c][y_c] <= 0) {
				if (board[x_c][y_c] <= 0 && visit[x_c][y_c] == 0) {
					wall++;
				}
				continue;
			}

			q.push({ x_c,y_c });
			visit[x_c][y_c] = 1;

			ice++;
		}
		board[x][y] -= wall;
		if (board[x][y] <= 0) {
			ice--;
			ccnt--;
		}

		if (board[x][y] > last) {
			last = board[x][y];
			col = x;
			row = y;
		}
	}

}
int main() {
	cin >> n >> m;
	ccnt = 0;
	col = 0;
	row = 0;

	int set = 0;
	last = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {

			cin >> board[i][j];
			if (board[i][j] != 0) {
				ccnt++;
				if (last < board[i][j]) {
					last = board[i][j];
					col = i;
					row = j;
				}
			}
		}
	}
	if (ccnt == 1) {
		cout << 0;
		return 0;
	}
	ice = ccnt;
	while (1) {


		ccnt = ice;
		ice = 0;
		bfs(col, row);
		if (ice != ccnt || ccnt == 1) {

			break;
		}

		if (board[col][row] <= 0 || ice == 0) {
			cout << 0;
			return 0;
		}
		set++;

		memset(visit, 0, sizeof(visit));
	}
	cout << set;

}