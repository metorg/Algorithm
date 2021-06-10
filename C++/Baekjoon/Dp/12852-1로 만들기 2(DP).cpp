#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include <stack>
#include<stdio.h>
#include<string.h>
#include<cstdio>
#include<set>

using namespace std;

int dp[1000000];
int remember[1000000] = { 0,-1, };

int n;

int main() {

	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 2;i <= n;i++) {
		dp[i] = dp[i - 1] + 1;
		remember[i] = i - 1;

		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
			dp[i] = dp[i / 2] + 1;
			remember[i] = i / 2;
		}

		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
			dp[i] = dp[i / 3] + 1;
			remember[i] = i / 3;
		}
	}

	cout << dp[n] << '\n' << n << ' ';
	
	while (1) {
		if (remember[n] == -1)break;
		cout << remember[n] << ' ';
		n = remember[n];
	}
}