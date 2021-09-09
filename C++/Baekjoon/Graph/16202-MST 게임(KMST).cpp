#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <set>

using namespace std;

typedef struct {
	int u;
	int v;
	int weight;
}edge;

int parent[1002];
vector<edge> v;
int n, m, k;
int num, num2;
int visit[10002];
int cnt,ans;

int find(int u) {
	if (u == parent[u])
		return u;

	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	
	parent[u] = v;
}

int compare(edge& a, edge& b) {
	return a.weight < b.weight;
}

int main()
{
	ios::sync_with_stdio(0);
	
	cin.tie(0);
	cin >> n >> m >> k;
	
	for (int i = 0; i < m; i++) {
		cin >> num >> num2;
		v.push_back({ num,num2,i + 1 });
	}
	sort(v.begin(), v.end(), compare);
	
	for (int j = 0; j < k; j++) {
		ans = 0;
		cnt = 0;

		for (int i = 1; i <= n; i++)
			parent[i] = i;	
		
		for (int i = 0; i < v.size(); i++) {
			if (visit[i])continue;
			
			if (find(v[i].u) != find(v[i].v)) {
				cnt++;
				merge(v[i].u, v[i].v);
				
				if (ans == 0) {
					visit[i] = 1;
				}

				ans += v[i].weight;
			}
		}

		if (cnt >= n - 1) {
			cout << ans << ' ';
		}
		else {
			cout << 0 << ' ';
		}
		
	}
}