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
#define MAX 100
#define INF 987654321
using namespace std;
int n, m, k;
int num, num2, weight;
int dist[MAX][MAX];
int board[MAX][MAX];


int xx[4] = { 0,0,1,-1 };
int yy[4] = { 1,-1,0,0 };
void BFS(int a, int b)
{
	queue<pair<int, int>>q;
	q.push({ a,b });
	dist[a][b] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int c_x = x + xx[i];
			int c_y = y + yy[i];

			if (c_x < 0 || c_y < 0 || c_x >= m || c_y >= n)continue;
			if (board[c_x][c_y] == 1) {


				if (dist[c_x][c_y] > dist[x][y] + 1) {
					dist[c_x][c_y] = dist[x][y] + 1;
					q.push({ c_x,c_y });
				}
			}
			else if (board[c_x][c_y] == 0) {
				if (dist[c_x][c_y] > dist[x][y]) {
					dist[c_x][c_y] = dist[x][y];
					q.push({ c_x,c_y });
				}
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	string a;
	for (int i = 0; i < m; i++) {
		cin >> a;
		for (int j = 0; j < a.length(); j++) {
			board[i][j] = a[j] - '0';
			dist[i][j] = INF;
		}
	}
	BFS(0, 0);
	cout << dist[m - 1][n - 1];
}