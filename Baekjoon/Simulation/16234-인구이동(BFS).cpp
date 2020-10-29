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
int visit[51][51];
int board[51][51];
int n, l, r;
int xx[4] = { 0,0,-1,1 };
int yy[4] = { 1,-1,0,0, };
int sm[10000];
int rs;
void bfs(int cnt, int start, int start2) {
	queue<pair<int, int>>q;
	int t = 0;
	int sum = 0;
	q.push({ start,start2 });

	sum += board[start][start2];
	t++;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int c_x = x + xx[i];
			int c_y = y + yy[i];
			if (c_x < 0 || c_y < 0 || c_x >= n || c_y >= n || visit[c_x][c_y]>0)continue;
			if (l <= abs(board[x][y] - board[c_x][c_y]) && abs(board[x][y] - board[c_x][c_y]) <= r) {
				q.push({ c_x,c_y });
				visit[c_x][c_y] = cnt;
				visit[x][y] = cnt;
				sum += board[c_x][c_y];
				t++;
			}
		}
	}
	if (t > 1) {
		sm[cnt] = sum / t;
		rs++;
	}
}
int main() {
	int result = 0;
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	while (1) {

		int msum = 0;
		int cnt = 1;
		rs = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j] == 0) {
					bfs(cnt, i, j);
					cnt++;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j] >= 1) {
					board[i][j] = sm[visit[i][j]];
					msum += board[i][j];
				}
			}

		}

		memset(visit, 0, sizeof(visit));
		memset(sm, 0, sizeof(sm));
		if (rs == 0) break;
		if (msum == 0)break;
		result++;

	}
	cout << result;
}