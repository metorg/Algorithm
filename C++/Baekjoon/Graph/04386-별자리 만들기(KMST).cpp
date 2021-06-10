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
	int u, v;
	double weight;
	edge(int u, int v, double weight) {
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

double compare(edge& a, edge& b) {
	return a.weight < b.weight;
}
int main() {
	vector<edge>v;
	vector<pair<double, double>> num;
	int n, m;
	double a, b, c;
	double ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	for (int i = 0;i < n;i++) {
		cin >> a >> b;
		num.push_back({ a,b });
	}
	double last = 0;
	for (int i = 0;i < num.size();i++) {
		last = 0;
		for (int j = i + 1;j < num.size();j++) {
			last = 0;
			last = sqrt(pow((num[i].first - num[j].first), 2) + pow((num[i].second - num[j].second), 2));
			v.push_back(edge(i, j, last));
		}
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		if (find(v[i].u) != find(v[i].v)) {
			merge(v[i].u, v[i].v);
			ans += v[i].weight;
		}
	}
	printf("%.2lf", ans);


}