#include<iostream>
#include<vector>
#include<string>

using namespace std;

int dp[50001] = { 0,1 };
int n;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;

	for (int i = 2; i <= n; i++) {
		dp[i] = 4;
		for (int j = 1; j*j <= i; j++) {
			dp[i] = min(dp[i], dp[i - (j * j)]+1);
		}
	}
	cout << dp[n];
	
}