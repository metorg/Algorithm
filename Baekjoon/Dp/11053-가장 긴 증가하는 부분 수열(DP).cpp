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
//BOJ_2606 1시 22분 start 1시 35분 finish
using namespace std;

int n, num;
int dp[1000];
vector<int> v;
int answer = 0;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> num;
		v.push_back(num);
		
		for (int j = 0;j <= i;j++) {
			if (v[i] > v[j]) dp[i] = max(dp[i], dp[j]);
		}
		dp[i] += 1;
		answer = max(answer, dp[i]);
	}
	cout << answer;
}