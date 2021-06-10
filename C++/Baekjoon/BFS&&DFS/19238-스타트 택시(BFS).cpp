/*이문제를 풀면서 고려해야 할 부분이 너무 많았다. 출발지점과 도착지점이 중복되는 것과
여러개의 출발지점이 도착지점은 한곳인 것 이런 반례들을 찾다보니 시간이 굉장히 오래걸리고
코드 역시 매우 복잡해졌다.*/
#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<memory.h>
#include<unordered_map>

using namespace std;
int board[21][21];
int board2[21][21][405];
int visit[21][21];
int n, m, o;
int start, start2;
int a, b, c, d;
int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,1,-1 };

vector<pair<pair<int, int>, int>> v;//탑승과 도착 할때 좌표와 연료량을 저장해주는 벡터

void bfs_depart() {
	int dis_cnt = 2e9;
	queue<pair<int, int>> q;
	queue<pair<int, int>> q2;
	if (board[v.front().first.first][v.front().first.second] > 0) {

		return;
	}
	visit[v.front().first.first][v.front().first.second] = 1;
	q.push({ v.front().first.first,v.front().first.second });
	q2.push({ v.front().second,0 });
	v.clear();
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int oil = q2.front().first;
		int dis = q2.front().second;
		q.pop();
		q2.pop();
		if (dis_cnt < dis) {
			return;
		}

		for (int i = 0;i < 4;i++) {
			int c_x = x + xx[i];
			int c_y = y + yy[i];
			if (c_x < 0 || c_y < 0 || c_x >= n || c_y >= n || board[c_x][c_y] == 1 || visit[c_x][c_y] == 1)continue;
			if (board[c_x][c_y] > 1) {
				if (oil - 1 < 0) {
					cout << -1;
					exit(0);
				}
				v.push_back({ {c_x,c_y},oil - 1 });
				dis_cnt = dis;
				visit[c_x][c_y] = 1;
			}
			else {
				q.push({ c_x,c_y });
				q2.push({ oil - 1 , dis + 1 });
				visit[c_x][c_y] = 1;
			}
		}
	}
	return;
}
int bfs_arrive(int target) {

	board[v.front().first.first][v.front().first.second] = 0;
	queue<pair<int, int>> q;
	queue<pair<int, int>>q2;
	visit[v.front().first.first][v.front().first.second] = 1;
	q.push({ v.front().first.first,v.front().first.second });
	q2.push({ v.front().second,0 });
	v.clear();
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int oil = q2.front().first;
		int dis = q2.front().second;
		q.pop();
		q2.pop();
		if (oil - 1 < 0) {
			cout << -1;
			exit(0);
		}
		for (int i = 0;i < 4;i++) {
			int c_x = x + xx[i];
			int c_y = y + yy[i];
			if (c_x < 0 || c_y < 0 || c_x >= n || c_y >= n || board2[c_x][c_y][0] == 1 || visit[c_x][c_y] == 1)continue;
			if (target == board2[c_x][c_y][target]) {

				v.push_back({ { c_x,c_y }, oil - 1 });
				return dis + 1;
			}
			else {
				q.push({ c_x,c_y });
				q2.push({ oil - 1,dis + 1 });
				visit[c_x][c_y] = 1;
			}
		}
	}
	return 0;
}
int main() {
	cin >> n >> m >> o;
	int last;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> board[i][j];
			board2[i][j][0] = board[i][j];
		}
	}
	cin >> start >> start2;
	v.push_back({ { start - 1, start2 - 1 }, o });
	for (int i = 2;i < m + 2;i++) {
		cin >> a >> b >> c >> d;
		board[a - 1][b - 1] = i;
		board2[c - 1][d - 1][i] = i;
	}
	for (int i = 0;i < m;i++) {
		bfs_depart();
		if (v.empty() == 1) {
			cout << -1;
			return 0;
		}
		sort(v.begin(), v.end());
		memset(visit, 0, sizeof(visit));
		last = bfs_arrive(board[v.front().first.first][v.front().first.second]);
		if (v.empty() == 1) {
			cout << -1;
			return 0;
		}
		memset(visit, 0, sizeof(visit));
		v[0].second = v[0].second + (last * 2);
	}
	cout << v[0].second;
}