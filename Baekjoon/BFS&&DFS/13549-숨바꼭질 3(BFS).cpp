#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include<stdio.h>
#include<string.h>
#include<cstdio>
#include<set>

using namespace std;

int n, m;
int visit[100002];


void bfs(int n) {
	priority_queue<pair<int, int>> q;
	q.push({ 0,n });
	visit[n] = 1;
	while (!q.empty()) {

		int cnt = -q.top().first;
		int cur = q.top().second;
		q.pop();
		visit[cur] = 1;

		if (cur == m) {
			cout << cnt;
			return;
		}

		if (cur * 2 <= 100001 && visit[cur * 2] == 0) q.push({ -cnt ,cur * 2 });
		if (cur + 1 <= 100001 && visit[cur + 1] == 0) q.push({ -(cnt + 1), cur + 1 });
		if (cur - 1 >= 0 && visit[cur - 1] == 0) q.push({ -(cnt + 1),cur - 1 });
	}
}
int main() {
	cin >> n >> m;
	bfs(n);

}


