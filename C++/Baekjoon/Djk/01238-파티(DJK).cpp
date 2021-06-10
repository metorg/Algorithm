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
#define MAX 1001
#define INF 987654321
using namespace std;
int Dist[MAX];
vector<pair<int, int>> v[MAX];
int n, m, num1, num2, weight;
int party;
int v2[1001];
void reset() {
	for (int i = 1; i <= n; i++)Dist[i] = INF;
}
void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	Dist[start] = 0;
	while (!pq.empty()) {
		int wt = -pq.top().first;
		int cur = pq.top().second;

		pq.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int nwt = v[cur][i].second;
			if (Dist[next] > wt + nwt) {
				Dist[next] = wt + nwt;
				pq.push({ -Dist[next],next });
			}
		}
	}

}
int main() {
	int answer = 0;
	cin >> n >> m >> party;
	for (int i = 0; i < m; i++) {
		cin >> num1 >> num2 >> weight;
		v[num1].push_back({ num2,weight });
	}

	reset();

	for (int i = 1; i <= n; i++) {
		if (i == party)continue;

		reset();
		dijkstra(i);
		v2[i] = Dist[party];

	}
	reset();
	dijkstra(party);
	for (int i = 1; i <= n; i++) {
		v2[i] += Dist[i];
		answer = max(answer, v2[i]);
	}

	cout << answer;

}