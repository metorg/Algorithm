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
int start, finish;
void dijkstra()
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	Dist[start] = 0;
	while (!pq.empty()) {
		int wt = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0;i < v[cur].size();i++) {
			int next = v[cur][i].first;
			int nwt = v[cur][i].second;
			if (Dist[next] > wt + nwt) {
				Dist[next] = wt + nwt;
				pq.push({ -Dist[next],next });
			}
		}
	}
	cout << Dist[finish];
}
int main() {
	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		cin >> num1 >> num2 >> weight;
		v[num1].push_back({ num2,weight });
	}
	cin >> start >> finish;
	for (int i = 1;i <= n;i++)Dist[i] = INF;
	dijkstra();

}