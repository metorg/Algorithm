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

using namespace std;

int n,m,weight,value;
vector<pair<int, int>> v;
int dp[101][100001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	v.push_back({ 0,0 });

	for (int i = 0;i < n;i++) {
		cin >> weight >> value;
		v.push_back({weight, value});
	}
	
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {

			if (j >= v[i].first) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].first] + v[i].second);
			else dp[i][j] = dp[i - 1][j];

		}
	}
	cout << dp[n][m];

}