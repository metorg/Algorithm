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

int n, m;
long long dp[101] = { 0,1,1,1,2,2,3,4,5,7,9 };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (int i = 11; i <= 100; i++) dp[i] = dp[i - 1] + dp[i - 5];
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		cout << dp[m]<<'\n';
	}


}
