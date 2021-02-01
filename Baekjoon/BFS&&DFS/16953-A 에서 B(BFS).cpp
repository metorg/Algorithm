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

void bfs() {

	priority_queue<pair<int, int>> pq;
	pq.push({ -1,n });

	while (!pq.empty()) {
		int cnt = -pq.top().first;
		int cur = pq.top().second;
		
		pq.pop();
	
		if (cur == m) {
			cout << cnt;
			return;
		}
		if (cur * 2 <= m)pq.push({ -(cnt + 1), cur * 2 });
		if (cur<= 1e8)pq.push({ -(cnt + 1),(cur * 10) + 1 });	
	}

	cout << -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	bfs();
}


