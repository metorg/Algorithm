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
#define MAX 20010
#define INF 987654321
using namespace std;
int n, m, k;
int num, num2, weight;
int Dist[MAX];

vector<pair<int, int>> v[MAX];
void Solution()
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,k });
	Dist[k] = 0;
	while (!pq.empty()) {
		int wt = -pq.top().first;
		int cur = pq.top().second;
		
		pq.pop();
		if (wt > Dist[cur])continue;

		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i].first;
			int nwt = v[cur][i].second;
			

			if (Dist[next] > wt + nwt) {
				Dist[next] = wt + nwt;
				pq.push({ -Dist[next],next });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (Dist[i] == INF)cout << "INF" << '\n';
		else cout << Dist[i] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	cin >> k;
	for (int i = 0; i < m; i++) {
		cin >> num >> num2 >> weight;
		v[num].push_back({ num2,weight });
	}
	for (int i = 1; i <= n; i++)Dist[i] = INF;
	Solution();

}