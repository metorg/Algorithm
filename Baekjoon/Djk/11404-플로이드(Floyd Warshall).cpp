#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include<stdio.h>
#include<string.h>
#include<cstdio>
#include<set>

#define INF 1e9

using namespace std;

int n, m, num, num2, weight;
int dp[101][101];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	
	fill(&dp[0][0],&dp[100][101], INF);
	
	for (int i = 1;i <= n;i++) dp[i][i] = 0;
	
	for (int i = 0;i < m;i++) {
		
		cin >> num >> num2 >> weight;
		if (dp[num][num2] > weight) dp[num][num2] = weight;
	}
	
	for (int k = 1;k <= n;k++) {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				if (dp[i][k] + dp[k][j] < dp[i][j]) dp[i][j] = dp[i][k] +dp[k][j];
			}
		}
	}

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			if (dp[i][j] == INF) cout << 0 << ' ';
			else cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
}

