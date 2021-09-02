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

int visit[2001];
vector<vector<int>> v(2001);
int n, m;
int num, num2;
int answer;

void dfs(int start,int cnt) {
	
	if (cnt == 5) {
		answer++;
		return;
	}

	for (int i = 0; i < v[start].size(); i++) {
		if (visit[v[start][i]] == 1)continue;
		visit[v[start][i]] = 1;
		dfs(v[start][i],cnt+1);
		if (answer>0)return ;
		visit[v[start][i]] = 0;
	}
	return;
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> num >> num2;
		v[num].push_back(num2);
		v[num2].push_back(num);
	}

	for (int i = 0; i <n; i++) {
		
		answer = 0;
		visit[i] = 1;
		dfs(i, 1);
		if (answer >0) {
			cout << 1;
			return 0;
		}
		memset(visit, 0, sizeof(visit));
	}
	cout << 0;
}

