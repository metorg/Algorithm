#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include<cstring>
#include<stack>
#include<string.h>
#include<stdio.h>

using namespace std;
	
char board[8][8];
int n = 8;

int xx[9] = { 1,-1,0,0,1,1,-1,-1,0 };
int yy[9] = { 0,0,1,-1,-1,1,-1,1,0 };

void board_shift() {
	for (int i = n-1; i >0; i--) {
		for (int j = 0; j < n; j++) {
			board[i][j] = board[i-1][j];
		}
	}
	for (int i = 0; i < n; i++) {
		board[0][i] = '.';
	}
}
int bfs() {
	int limit = 1;
	queue<pair<pair<int, int>,int>> q;
	q.push({ { 7,0 },0 });
	
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second;
		q.pop();
		if (limit == dist) {
			board_shift();
			limit++;
		}
		if (board[x][y] == '#')continue;
		
		if (x == 0 && y == 7)return 1;
		for (int i = 0; i < 9; i++) {
			int c_x = xx[i] + x;
			int c_y = yy[i] + y;
			if (c_x < 0 || c_y < 0 || c_x >= n || c_y >= n || board[c_x][c_y] == '#')continue;

			q.push({{ c_x,c_y },dist + 1});
		}
	}
	return 0;
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	cout << bfs();

}