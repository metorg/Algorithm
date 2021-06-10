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

#define INF 2e9

using namespace std;

int tc;
int n, m, w;
int s, e, t;
int flag;
int dist[501];
int cnt;
vector<pair<int, int>> v[501];


int bellman_ford() {
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			for (int k = 0;k < v[j].size();k++) {
				if (dist[j] != INF && dist[v[j][k].first] > v[j][k].second + dist[j]) {
					if (i == n)return 1;				
					dist[v[j][k].first] = v[j][k].second + dist[j];
				}
			}
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> tc;
	for (int i = 0;i < tc;i++) {
		cin >> n >> m >> w;
		for (int i = 1;i <= n;i++) v[i].clear();
		fill(dist, dist + n, INF);
		flag = 0;
		for (int j = 0;j < m;j++) {
			cin >> s >> e >> t;
			v[s].push_back({ e,t });
			v[e].push_back({ s,t });
		}
		for (int j = 0;j < w;j++) {
			cin >> s >> e >> t;
			v[s].push_back({ e,-t });
		}
		flag=bellman_ford();
	
		if (flag == 1) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

}


