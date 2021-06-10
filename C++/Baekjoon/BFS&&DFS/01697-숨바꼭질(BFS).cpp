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
int visit[200040] = { 0, };
int n, m;
int cnt = 0;
vector<int> v;
int bfs() {
	queue<pair<int, int>> q;
	q.push({ n,cnt });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == m) {
			return y;
		}

		if (!visit[x * 2] && x * 2 <= 100000) {
			visit[x * 2] = 1;
			int k = y;
			k++;
			q.push({ x * 2,k });

		}
		if (!visit[x - 1] && x - 1 > 0) {
			visit[x - 1] = 1;
			int k = y;
			k++;
			q.push({ x - 1,k });

		}
		if (!visit[x + 1] && x + 1 <= 100000) {
			visit[x + 1] = 1;
			int k = y;
			k++;
			q.push({ x + 1,k });

		}
	}
}


int main() {
	cin >> n >> m;
	if (n == m) {
		cout << 0;
		return 0;
	}
	else if (n > m) {
		cout << n - m;
		return 0;
	}
	else
		cout << bfs();

}
