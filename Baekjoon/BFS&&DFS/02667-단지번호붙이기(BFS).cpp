#include <iostream>
#include <vector> 
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>

using namespace std;

int c;
int cnt;
string a;
int visit[26][26] = { 0, };
int xx[4] = { 0, 0 ,-1 ,1 };
int yy[4] = { -1, 1, 0, 0 };

void bfs(int i, int j) {
	cnt = 0;
	int x_c;
	int y_c;
	queue<pair<int, int>>q;
	q.push({ i,j });
	visit[i][j] = 0;
	cnt++;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {

			x_c = x + xx[i];
			y_c = y + yy[i];
			if (x_c < 0 || y_c < 0 || x_c >= c || y_c >= c || visit[x_c][y_c] == 0) {
				continue;

			}

			q.push(make_pair(x_c, y_c));
			visit[x_c][y_c] = 0;
			cnt++;

		}
	}


}
int main() {
	cin >> c;
	for (int i = 0;i < c;i++) {
		cin >> a;
		for (int j = 0;j < c;j++) {
			visit[i][j] = a[j] - '0';
		}

	}

	vector<int> v;

	for (int i = 0;i < c;i++) {
		for (int j = 0;j < c;j++) {
			if (visit[i][j] == 1) {
				bfs(i, j);
				if (cnt > 0) {
					v.push_back(cnt);
				}

			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (auto j : v)
		cout << j << '\n';
}