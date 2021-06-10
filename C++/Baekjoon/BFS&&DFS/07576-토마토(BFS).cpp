#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stack>
#include<memory.h>

using namespace std;
int visit[1002][1002];
int visit2[1002][1002];
int n, m;
int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,-1,1 };
int mmax;

vector<pair<int, int>> v;
void bfs() {
	mmax = 0;
	int cnt = 0;
	queue<pair<pair < int, int>, int>> q;
	for (int i = 0;i < v.size();i++) {
		visit[v[i].first][v[i].second] = cnt;
		visit2[v[i].first][v[i].second] = 1;
		cnt++;
		q.push({ { v[i].first,v[i].second }, cnt });
		cnt = 0;
	}
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int k = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int x_c = x + xx[i];
			int y_c = y + yy[i];
			if (x_c < 0 || y_c < 0 || x_c >= m || y_c >= n || visit[x_c][y_c] == -1 || visit2[x_c][y_c] == 1) {
				continue;
			}
			int ccnt = k;
			ccnt++;
			q.push({ { x_c,y_c }, ccnt });
			visit[x_c][y_c] = k;
			if (k > mmax) {
				mmax = k;
			}
			visit2[x_c][y_c] = 1;
		}
	}
}
int main() {
	int count = 0;
	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			cin >> visit[i][j];
			if (visit[i][j] == 0) {
				visit[i][j] = -3;
			}
			else if (visit[i][j] == 1) {
				v.push_back({ i,j });
			}
		}
	}
	bfs();
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			if (visit[i][j] == 0 || visit[i][j] == -3) {
				count++;
			}

		}
	}
	if (count == v.size()) {
		cout << mmax;
	}
	else
		cout << -1;
}