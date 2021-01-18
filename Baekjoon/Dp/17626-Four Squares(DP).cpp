#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	int dp[50010] = { 0, 1,};
	cin >> n;

	for (int i = 2; i <= n; i++) {
		dp[i] = 4;
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - (j * j)] + 1);
		}
	}
	cout << dp[n];
}