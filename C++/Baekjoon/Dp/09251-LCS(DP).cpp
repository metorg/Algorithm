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

int dp[1002][1002];

int main() {

	string a, b, c;
	a.push_back('\0');
	b.push_back('\0');
	cin >> c;
	a += c;
	cin >> c;
	b += c;

	for (int i = 1; i < b.size(); i++) {
		for (int j = 1; j < a.size(); j++) {

			if (b[i] == a[j]) dp[i][j] = dp[i - 1][j - 1] + 1;

			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[b.size() - 1][a.size() - 1];
}


