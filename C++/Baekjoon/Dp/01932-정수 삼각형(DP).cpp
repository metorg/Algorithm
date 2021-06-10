#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include<stdio.h>
#include<string.h>
#include<set>

using namespace std;

int n, num;
vector<vector<int>> dp(501);
int ans = -1e9;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j <= i;j++) {
			cin >> num;
			dp[i].push_back(num);
		}
	}
	for (int i = 1;i < n;i++) {
		for (int j = 0;j < dp[i].size();j++) {
			if (j == 0)dp[i][j] += dp[i - 1][j];
			else if (j == dp[i].size() - 1)dp[i][j] += dp[i - 1][dp[i - 1].size() - 1];
			else dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);
			ans = max(ans, dp[i][j]);
		}
	}
	
	cout << ans;
}