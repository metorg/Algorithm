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

long long n, b;
int dp[5][5];
int reset_dp[5][5];
int answer[5][5];

void calculation(int a[5][5], int b[5][5]) {

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			reset_dp[i][j] = 0;
			for (int k = 0;k < n;k++) {
				reset_dp[i][j] += a[i][k] * b[k][j];
			}
			reset_dp[i][j] = reset_dp[i][j] % 1000;

		}
	}
	memcpy(a, reset_dp, sizeof(reset_dp));
}

int main() {

	ios::sync_with_stdio(false);

	cin >> n >> b;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> dp[i][j];
			if (i == j) answer[i][j] = 1;
		}
	}

	while (b) {
		long long cnt = b % 2;
		if (cnt)calculation(answer, dp);
		calculation(dp, dp);
		b /= 2;
	}
	

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << answer[i][j] << ' ';
		}
		cout << '\n';
	}

}