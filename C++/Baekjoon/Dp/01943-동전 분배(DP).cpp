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

int prev_max_dp[3];
int prev_min_dp[3];
int max_dp[3];
int min_dp[3];
int n,num;

int main() {

	ios::sync_with_stdio(0);
	
	cin >> n;

	for (int j = 0;j < 3;j++) {
		cin >> prev_max_dp[j];
		prev_min_dp[j] = prev_max_dp[j];
	}

	for (int i = 1;i < n;i++) {
		
		for (int j = 0;j < 3;j++) {
			cin >> num;
			if (j == 0) {
				max_dp[j] = max(prev_max_dp[0], prev_max_dp[1]) + num;
				min_dp[j] = min(prev_min_dp[0], prev_min_dp[1]) + num;
			}
			else if (j == 2) {
				max_dp[j] = max(prev_max_dp[2], prev_max_dp[1]) + num;
				min_dp[j] = min(prev_min_dp[2], prev_min_dp[1]) + num;
			}
			else {
				max_dp[j] = max(prev_max_dp[j], max(prev_max_dp[j - 1], prev_max_dp[j + 1])) + num;
				min_dp[j] = min(prev_min_dp[j], min(prev_min_dp[j - 1], prev_min_dp[j + 1])) + num;
			}
		}

		for (int i = 0;i < 3;i++) {
			prev_max_dp[i] = max_dp[i];
			prev_min_dp[i] = min_dp[i];
		}
	}

	cout << max(prev_max_dp[0], max(prev_max_dp[1], prev_max_dp[2])) << ' ';
	cout << min(prev_min_dp[0], min(prev_min_dp[1], prev_min_dp[2]));

}