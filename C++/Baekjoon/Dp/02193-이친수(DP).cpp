#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stack>
#include<memory.h>
#include<unordered_map>
#include<set>
#include<bitset>
#include<string>
#define INF 1e9

using namespace std;

int n;
long long dp[91] = { 0,1 };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 2; i <= n; i++) {	
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout<<dp[n];
}