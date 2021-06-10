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
int n, m, k;
int board[100][100];
int visit[100][100];
int xx[4] = { 0,0,-1,1 };
int yy[4] = { 1,-1,0,0 };
int ccnt;

using namespace std;
void bfs(int i, int j) {
	ccnt = 1;
	int cnt = 1;
	queue<pair<pair<int, int>, int>> q;
	q.push({ { i,j }, cnt });
	visit[i][j] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int k = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int x_c = x + xx[i];
			int y_c = y + yy[i];
			if (x_c < 0 || y_c < 0 || x_c >= n || y_c >= m || visit[x_c][y_c] == 1 || board[x_c][y_c] == 1)continue;
			q.push({ { x_c,y_c }, cnt + 1 });
			visit[x_c][y_c] = 1;
			ccnt++;
		}

	}
}
int main() {
	vector<int> size;
	cin >> n >> m >> k;
	int a, b, c, d;

	for (int i = 0;i < k;i++) {
		cin >> a >> b >> c >> d;
		for (int i = b;i < d;i++) {
			for (int j = a;j < c;j++) {
				board[i][j] = 1;
			}
		}
	}


	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (board[i][j] == 0 && visit[i][j] == 0) {
				bfs(i, j);
				size.push_back(ccnt);
			}
		}
	}
	sort(size.begin(), size.end());
	cout << size.size() << '\n';
	for (int i = 0;i < size.size();i++) {
		cout << size[i] << ' ';
	}
}