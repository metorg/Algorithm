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

int n;
int dp[1000] = { 1,1 };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 2;i <= n;i++) {
		dp[i] = dp[i-2] + dp[i - 1];
		dp[i] = dp[i] % 10007;
	}
	cout << dp[n];
}
