#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> v[10001];
int visit[10001];
int n, m, k, num1, num2;
int answer = 1e9;

typedef struct {
	int cur;
	int dist;
}info;


void visitReset(){
	for(int i=1;i<=n;i++)visit[i]=0;
}

void bfs(int start, int end) {
	queue<info> q;
	visit[start] = 1;
	q.push({ start,1 });

	while (!q.empty()) {
		int cur = q.front().cur;
		int dist = q.front().dist;
		q.pop();
		if (end == cur) {
			answer = min(answer, dist);
			return;
		}
		for (int i = 0; i < v[cur].size(); i++) {
			if (visit[v[cur][i]])continue;
			visit[v[cur][i]] = 1;
			q.push({ v[cur][i],dist + 1 });
		}
	}
}

int main() {

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		cin >> num1 >> num2;
		v[num1].push_back(num2);
	}
	for (int i = 0; i < v[k].size(); i++) {
		bfs(v[k][i], k);
		visitReset();
	}
	if (answer == 1e9)cout << -1;
	else cout << answer;

	return 0;
}
