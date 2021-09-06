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
vector<pair<int, int>> v[201];
int dist[201];
int route[201];
int num, num2, weight;

void dijkstra(int start) {

	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start});

	for (int i = 1; i <= n; i++) {
		dist[i] = 1e9;
	}
	dist[start] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost)continue;

		for (int i = 0; i < v[cur].size(); i++) {
			int nxt = v[cur][i].first;
			int nxt_cost = v[cur][i].second;

			if (dist[nxt] > cost + nxt_cost) {
				dist[nxt] = cost + nxt_cost;
				route[nxt] = cur;
				pq.push({ -dist[nxt],nxt });
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (i == start) {
			cout << "- ";
		}
		else {
			int temp = i;//역추적
			while (true) {
				if (route[temp] == start) {
					cout << temp << ' ';
					break;
				}
				else {
					temp = route[temp];
				}
			}
		}
	}
	cout << '\n';
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> num >> num2 >> weight;
		v[num].push_back({ num2,weight });
		v[num2].push_back({ num,weight });
	}

	
	for (int i = 1; i <= n; i++) {
		dijkstra(i);
	}
	
}