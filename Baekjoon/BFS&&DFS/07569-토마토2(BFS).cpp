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
int visit[101][101][101];
int visit2[101][101][101];
int n, m, l;
int xx[6] = { -1,1,0,0,0,0 };
int yy[6] = { 0,0,-1,1,0,0 };
int zz[6] = { 0,0,0,0,-1,1 };
int mmax;

vector<pair<pair<int, int>, int>> v;
void bfs() {
	mmax = 0;
	int cnt = 0;
	queue<pair<int, int>> q;
	queue<pair<int, int>> q2;
	for (int i = 0;i < v.size();i++) {
		visit[v[i].first.first][v[i].first.second][v[i].second] = cnt;
		visit2[v[i].first.first][v[i].first.second][v[i].second] = 1;
		cnt++;
		q.push({ v[i].first.first,v[i].first.second });
		q2.push({ v[i].second , cnt });
		cnt = 0;
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int z = q2.front().first;
		int b = q2.front().second;
		q.pop();
		q2.pop();
		for (int i = 0;i < 6;i++) {
			int x_c = x + xx[i];
			int y_c = y + yy[i];
			int z_c = z + zz[i];
			if (x_c < 0 || y_c < 0 || x_c >= m || y_c >= n || z_c < 0 || z_c >= l || visit[x_c][y_c][z_c] == -1 || visit2[x_c][y_c][z_c] == 1) {
				continue;
			}
			int ccnt = b;
			ccnt++;
			q.push({ x_c,y_c });
			q2.push({ z_c,ccnt });
			visit[x_c][y_c][z_c] = b;
			if (b > mmax) {
				mmax = b;
			}
			visit2[x_c][y_c][z_c] = 1;
		}
	}
}
int main() {
	int count = 0;
	cin >> n >> m >> l;
	for (int k = 0;k < l;k++) {
		for (int i = 0;i < m;i++) {
			for (int j = 0;j < n;j++) {
				cin >> visit[i][j][k];
				if (visit[i][j][k] == 0) {
					visit[i][j][k] = -3;
				}
				else if (visit[i][j][k] == 1) {
					v.push_back({ { i,j }, k });
				}
			}
		}
	}
	bfs();

	for (int k = 0;k < l;k++) {
		for (int i = 0;i < m;i++) {
			for (int j = 0;j < n;j++) {
				if (visit[i][j][k] == 0 || visit[i][j][k] == -3) {
					count++;
				}

			}
		}
	}

	if (count == v.size()) {
		cout << mmax;
	}
	else
		cout << -1;
}