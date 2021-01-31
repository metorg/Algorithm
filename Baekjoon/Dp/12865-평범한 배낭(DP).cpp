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

int n, m, weight, value;
vector<pair<int, int>> v;
int dp[100001];
int ans = 0;
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	v.push_back({ 0,0 });

	for (int i = 0;i < n;i++) {
		cin >> weight >> value;
		v.push_back({ weight, value });
	}

	for (int i = 0;i < v.size();i++) {
		for (int j = m;j >= v[i].first; j--) dp[j] = max(dp[j], dp[j - v[i].first] + v[i].second);
	}

	cout << dp[m];

}