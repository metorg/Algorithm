#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>

using namespace std;
//48분 스타트

int n, m;
int num, num2;
int board[101];
int visit[101];

int bfs() {
	queue<pair<int, int>> q;
	q.push({ 0, 1 });
	visit[1] = 1;
	
	while (!q.empty()) {
		int cnt = q.front().first;
		int cur = q.front().second;
		q.pop();
		if (cur == 100) return cnt;
		if (cur > 100)continue;
		for (int i = 1; i <= 6; i++) {
			
			if (board[cur + i] == 0) {
				if (visit[cur + i])continue;
				q.push({ cnt + 1,cur + i });
			}
			else {
				if (visit[board[cur + i]])continue;
				q.push({ cnt + 1,board[cur + i] });
			}
			
			visit[cur + i]=1;
		}
	}
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		cin >> num >> num2;
		board[num] = num2;
	}
	cout<<bfs();
}