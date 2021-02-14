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

int n, m;
long long result=0;
string dp[101][101];

string calculation(string a, string b) {//Å«¼öÀÇ µ¡¼À ¾Ë°í¸®Áò
	
	long long sum=0;
	string result;
	
	while (!a.empty() || !b.empty() || sum != 0) {
		if (!a.empty()) {
			sum += a.back() - '0';
			a.pop_back();
		}
		if (!b.empty()) {
			sum += b.back() - '0';
			b.pop_back();
		}
		result += (sum % 10) + '0';
		sum /= 10;
	}
	
	reverse(result.begin(), result.end());
	
	return result;
}

string combination(int r, int t) {
	
	if (r == t || t == 0)return "1";
	if (dp[r][t] != "")return dp[r][t];	
	return dp[r][t] = calculation(combination(r - 1, t - 1), combination(r - 1, t));

}

int main() {
	ios::sync_with_stdio(false);
	
	cin >> n >> m;	
	cout << combination(n, m);

	
}