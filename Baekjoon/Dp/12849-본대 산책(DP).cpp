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

long long dp[8] = { 1,0,0,0,0,0,0,0 };
int walk_time;
int line = 1000000007;
using namespace std;

void walk() {
	long long tmp[8];
	tmp[0] = (dp[1] + dp[2]) % line;
	tmp[1] = (dp[0] + dp[2] + dp[3]) % line;
	tmp[2] = (dp[0] + dp[1] + dp[3] + dp[4]) % line;
	tmp[3] = (dp[1] + dp[2] + dp[4] + dp[5]) % line;
	tmp[4] = (dp[2] + dp[3] + dp[5] + dp[7]) % line;
	tmp[5] = (dp[3] + dp[4] + dp[6]) % line;
	tmp[6] = (dp[5] + dp[7]) % line;
	tmp[7] = (dp[4] + dp[6]) % line;
	
	memcpy(dp, tmp, sizeof(tmp));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> walk_time;
	for (int i = 0;i < walk_time;i++) {
		walk();
	}
	cout << dp[0];
	
	
}