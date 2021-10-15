#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<set>
#include<vector>
#include<queue>

using namespace std;

int n;
int dp[1001] = { 1,1,3 };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 3; i <= n; i++) {
			dp[i] = (dp[i - 1] + dp[i - 2]*2)%10007 ;
	}

	cout << dp[n];
}