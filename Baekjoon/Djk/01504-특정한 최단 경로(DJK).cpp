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
#define MAX 1010
#define INF 987654321
using namespace std;
int Dist[MAX];
vector<pair<int, int>> v[MAX];
int n, m, num1, num2, weight;
int start1, start2;
int flag;
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

	int r1 = 0, r2 = 0;
	int flag = 0, flag2 = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> num1 >> num2 >> weight;
		v[num1].push_back({ num2,weight });
		v[num2].push_back({ num1,weight });
	}
	cin >> start1 >> start2;
	reset();

	dijkstra(1);
	r1 = Dist[start1];
	r2 = Dist[start2];
	reset();
	dijkstra(start2);
	r2 = r2 + Dist[start1];
	if (Dist[start1] == INF) {
		flag++;
	}
	reset();
	dijkstra(start1);
	r2 = r2 + Dist[n];
	r1 = r1 + Dist[start2];
	if (Dist[start2] == INF) {
		flag2++;
	}
	reset();
	dijkstra(start2);
	r1 = r1 + Dist[n];
	if (flag != 0 && flag2 != 0) {
		cout << -1;
	}
	else {
		cout << min(r1, r2);
	}
}