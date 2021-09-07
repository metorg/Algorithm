#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include<set>

using namespace std;

int n, m;
int num, num2;
int start, finish;
vector<int> v[10001];
int visit[10001];
int route[10001];

int bfs() {
	
	queue<pair<int,int>> q;
	q.push({ start,0 });
	visit[start] = 1;
	
	int cnt = 0;

	while (!q.empty()) {
	
		int cur = q.front().first;
		int dist = q.front().second;
		q.pop();
		
		
		if (cur == finish&&cnt==0) {
			memset(visit, 0, sizeof(visit));
			cnt++;
			int tmp = cur;
			
			while (tmp) {
				visit[route[tmp]] = 1;
				tmp = route[tmp];
			}
			
			visit[cur] = 1;
			visit[start] = 0;
			
			while (!q.empty()) {
				q.pop();
			}
			q.push({ cur,dist });			
		}
				
		for (int i = 0; i < v[cur].size(); i++) {
			if (visit[v[cur][i]])continue;
			q.push({ v[cur][i],dist + 1 });
			route[v[cur][i]] = cur;
			visit[v[cur][i]] = 1;
			if (v[cur][i] == start)return dist + 1;
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> num >> num2;
		v[num].push_back(num2);
		v[num2].push_back(num);
	}
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}
	cin >> start >> finish;
	cout<< bfs();
}