#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stack>
#include<memory.h>
#include<unordered_map>
using namespace std;

int dp[1001][1001];

string a, b;
int main() {

	ios::sync_with_stdio(0);
	cin >> a >> b;
	
	for (int i = 1;i <= a.length();i++) {
		for (int j = 1;j <= b.length();j++) {

			if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

		}
	}
	
	int i = a.length();
	int j = b.length();
	
	string ans = "";

	while (dp[i][j]) {
		if (dp[i][j] == dp[i - 1][j]) i--;
		else if (dp[i][j] == dp[i][j - 1]) j--;
		else {
			ans = a[i - 1] + ans;
			i--;
			j--;
		}
	}

	cout << dp[a.length()][b.length()] << '\n' << ans;



}