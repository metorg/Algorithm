#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<set>
#include<vector>
#include<queue>

using namespace std;

int n;
int dp[1000001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) dp[i]=min(dp[i],dp[i / 2] + 1);
		if (i % 3 == 0) dp[i]=min(dp[i], dp[i / 3] + 1);
	}
	cout << dp[n];


}