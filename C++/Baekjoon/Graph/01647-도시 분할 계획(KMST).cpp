#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stack>
#include<memory.h>
#include<unordered_map>
using namespace std;

int parent[10001];

struct edge {
	int u, v, weight;
	edge(int u, int v, int weight) {
		this->u = u;//this 는 멤버 변수를 초기화 활대 사용(자기자신을 가르키는 키워드)
		this->v = v;
		this->weight = weight;
	}
};

int find(int u) {
	if (u == parent[u])
		return u;

	return parent[u] = find(parent[u]);
}
void merge(int u, int v) {//간선이 한번 연결됬으면 정점끼리 연결된걸로 합쳐준다
	u = find(u);
	v = find(v);

	parent[v] = u;
}
bool compare(const edge& a, const edge& b) {
	return a.weight < b.weight;
}

int main() {
	vector<edge>v;
	int n, m;
	int cnt = 0;
	int a, b, c;

	long long ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v.push_back(edge(a, b, c));
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		if (cnt == n - 2)break;
		if (find(v[i].u) != find(v[i].v)) {
			merge(v[i].u, v[i].v);
			cnt++;
			ans += v[i].weight;
		}

	}
	cout << ans;


}