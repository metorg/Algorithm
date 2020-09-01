#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stack>
#include<memory.h>
/*ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);*/

using namespace std;

int visit[101][101];
int board[101][101];
int num;
int num2;
int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,1,-1 };


void bfs(int i, int j) {

	int x_c;
	int y_c;
	queue<pair<int, int>>q;
	q.push({ i,j });
	visit[i][j] = 2;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			x_c = x + xx[i];
			y_c = y + yy[i];
			if (x_c < 0 || y_c < 0 || x_c >= num || y_c >= num2 || visit[x_c][y_c] >= 1) {
				if (visit[x_c][y_c] >= 1) {
					visit[x_c][y_c] += 1;
					if (visit[x_c][y_c] >= 3) {
						board[x_c][y_c] = 0;

					}
				}
				continue;

			}
			q.push(make_pair(x_c, y_c));
			visit[x_c][y_c] = 2; //방문 처리 
		}
	}
}

int main() {
	int all_cnt = 0;
	cin >> num >> num2;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0;i < num;i++) {
		for (int j = 0;j < num2;j++) {

			cin >> board[i][j];
			if (board[i][j] == 1) {
				all_cnt++;
			}

		}
	}
	int ccnt = 0;
	int k;
	while (1) {
		int cheese_cnt = 0;
		memcpy(visit, board, sizeof(board));
		bfs(0, 0);
		ccnt++;

		for (int i = 0;i < num;i++) {
			for (int j = 0;j < num2;j++) {
				if (board[i][j] != 0) {
					cheese_cnt++;
				}
			}
		}
		if (cheese_cnt == 0)
		{
			cout << ccnt;
			break;
		}
	}
}