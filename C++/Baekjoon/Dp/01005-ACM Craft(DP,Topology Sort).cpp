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

vector<int> v[1001];
int game;
int n, m;
int num, num2,target;
int craft_time[1001];
int dp[1001];
int inDegree[1001];

void topologySort() {//위상정렬 알고리즘
	
	queue<int> q;
	
	for (int i = 1;i <= n;i++) {
		if (inDegree[i] == 0) {
			q.push(i);
			inDegree[i]--;
		}
	}
	
	while (!q.empty()) {
		
		
		int x = q.front();
		q.pop();
		for (int i = 0;i < v[x].size();i++) {
			dp[v[x][i]] = max(dp[x] + craft_time[v[x][i]], dp[v[x][i]]);
			inDegree[v[x][i]]--;
			if (inDegree[v[x][i]] == 0)q.push(v[x][i]);
		}
	}
	
	cout << dp[target] << '\n';
}

int main() {
	
	ios::sync_with_stdio(0);
	
	cin >> game;
	
	for (int j = 0;j < game;j++) {
		
		cin >> n >> m;
		for (int i = 1;i <= n;i++) {
			cin >> num;
			craft_time[i] = num;
			dp[i] = craft_time[i];
		}
		for (int i = 0;i < m;i++) {
			
			cin >> num >> num2;
			
			v[num].push_back(num2);
			inDegree[num2]++;
			
		}
		cin >> target;
		
		topologySort();
		
		for (int i = 0;i <= n;i++) v[i].clear();		
		memset(craft_time, 0, sizeof(craft_time));
		memset(dp, 0, sizeof(dp));
		memset(inDegree, 0, sizeof(inDegree));

	}

}