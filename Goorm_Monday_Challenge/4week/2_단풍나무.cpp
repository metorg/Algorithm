#include <iostream>
#include <queue>

//start 4:23 end 4:55 32분 소요

using namespace std;

typedef struct {
	int x;
	int y;
	int value;
}tree;

queue<tree> q;
vector<tree> v;
vector<tree> c_q;
int n;
int board[41][41];
int xx[4] = { 0,0,1,-1 };
int yy[4] = { 1,-1,0,0 };
int day = 0;

void reset() {
	for (int i = 0; i < v.size(); i++) {
		board[v[i].x][v[i].y] = v[i].value;
	}
	v.clear();
}

int bfs(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int c_x = x + xx[i];
		int c_y = y + yy[i];
		if (c_x < 0 || c_y < 0 || c_x >= n || c_y >= n || board[c_x][c_y]>0)continue;
		cnt++;
	}
	return cnt;
}

void stain() {
	while (!q.empty()) {
		
		int x = q.front().x;
		int y = q.front().y;
		int value = q.front().value;
		int tmp = value - bfs(x, y);
		
		if (tmp <= 0)v.push_back({ x,y,0 });
		
		else {
			v.push_back({ x,y,tmp });
			c_q.push_back({ x,y,tmp });
		}
		q.pop();
	}
	
	for (int i = 0; i < c_q.size(); i++) {
		q.push({ c_q[i].x,c_q[i].y,c_q[i].value });
	}
	
	c_q.clear();
}


int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0)q.push({ i,j,board[i][j] });
		}
	}
	while (!q.empty()) {
		stain();
		reset();
		day++;
		
	}
	cout << day;

	return 0;
}
