#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9
//pq는 구조체 사용 불가 내부라이브러리에서 sort를 진행하기때문에 명심할것
using namespace std;

int dist[1001];
vector<int> v[5001];
int n, m, k;
int num, num2;

void dijkstra() {
	
	priority_queue<pair<int,int>> pq;
	pq.push({ 0,1 });
	dist[1] = 0;

	while (!pq.empty()) {
		int wt = -pq.top().first;
		int start = pq.top().second;
		pq.pop();

		if (dist[start] < wt)continue;

		for (int i = 0; i <v[start].size(); i++) {
			int nxt_start = v[start][i];
			int nxt_wt = wt + 1;
			
			if (nxt_wt < dist[nxt_start]) {
				dist[nxt_start] = nxt_wt;
				pq.push({ -dist[nxt_start],nxt_start });
			}
		}
	}
	return;
}

int main() {


	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	
	for (int i = 0; i < m; i++) {
		cin >> num >> num2;
		v[num].push_back(num2);
		v[num2].push_back(num);
	}

	for (int i = 0; i <= n; i++) {
		dist[i] = INF;
	}

	dijkstra();
	
	if (k >= dist[n])cout << "YES";
	else cout << "NO";

}
