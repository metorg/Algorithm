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
int num, num2, cost;
vector<pair<int,int>> v[1001];
vector<int> route_answer;
int dist[1001];
int route[1001];
int start, finish;

void dijkstra() {

	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int wt = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		
		if (dist[cur] < wt)continue;

		for (int i = 0; i < v[cur].size(); i++) {
			int nxt = v[cur][i].first;
			int nxt_wt = v[cur][i].second;
			
			//업데이트할 때마다 route 업데이트
			if (dist[nxt] > wt + nxt_wt) {
				route[nxt] = cur;
				dist[nxt] = wt + nxt_wt;
				pq.push({ -dist[nxt],nxt });
			}
		}
	}

}



int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> num >> num2 >> cost;
		v[num].push_back({ num2,cost });
	}
	for (int i = 1; i <= n; i++) dist[i] = 1e9;
	cin >> start >> finish;
	
	dist[start] = 0;
	dijkstra();
	cout << dist[finish]<<'\n';
	
	int temp = finish;
	//역순으로 answer에 노드 값들을 push
	while (temp)
	{
		route_answer.push_back(temp);
		temp = route[temp];
	}

	cout << route_answer.size()<<'\n';
	for (int i = route_answer.size() - 1; i >= 0; i--) {
		cout << route_answer[i] << ' ';
	}	
}


