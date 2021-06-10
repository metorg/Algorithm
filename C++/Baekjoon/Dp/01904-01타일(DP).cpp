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


using namespace std;

int dp[1000000] = { 0,1,2 };
int n;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 3; i <= n; i++)  dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;

	cout << dp[n];
}