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
int visit[250][250];
char board[250][250];
vector<pair<int, int>> wolf;
vector<pair<int, int>> w_c;
vector<pair<int, int>> k_c;
int xx[4] = { -1,1,0,0, };
int yy[4] = { 0,0,1,-1 };
int k, v;
void bfs(int start, int start2) {
	queue<pair<int, int>> q;
	q.push({ start,start2 });
	w_c.push_back({ start,start2 });
	visit[start][start2] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int c_x = x + xx[i];
			int c_y = y + yy[i];
			if (c_x < 0 || c_y < 0 || c_x >= n || c_y >= m || board[c_x][c_y] == '#' || visit[c_x][c_y] == 1)continue;
			if (board[c_x][c_y] == 'v') {
				w_c.push_back({ c_x,c_y });
				q.push({ c_x,c_y, });
				visit[c_x][c_y] = 1;
			}
			else if (board[c_x][c_y] == 'k') {
				k_c.push_back({ c_x,c_y });
				q.push({ c_x,c_y });
				visit[c_x][c_y] = 1;
			}
			else {
				q.push({ c_x,c_y });
				visit[c_x][c_y] = 1;
			}
		}
	}
	if (w_c.size() < k_c.size()) {
		v -= w_c.size();
	}
	else
		k -= k_c.size();

}
int main() {
	k = 0;
	v = 0;
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> board[i][j];
			if (board[i][j] == 'v') {
				wolf.push_back({ i,j });
				v++;
			}
			else if (board[i][j] == 'k') {
				k++;
			}
		}
	}
	for (int i = 0;i < wolf.size();i++) {
		bfs(wolf[i].first, wolf[i].second);
		w_c.clear();
		k_c.clear();
	}
	cout << k << ' ' << v;
}