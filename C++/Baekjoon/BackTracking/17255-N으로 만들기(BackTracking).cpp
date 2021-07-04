#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include<cstring>
#include<stack>
#include<string.h>
#include<stdio.h>

using namespace std;
	
int answer = 0;
string n;
set<char> v;
int arr[10];

void dfs(string total, int depth) {
	
	if (depth == n.length()) {
		if (total == n) {
				
			answer++;
		}
		return;
	}
	
	for (char x : v) {
		int num = x - '0';
		if (arr[num] > 0) {
			arr[num]--;
			if (x + total != total + x)
			{
				dfs(x + total, depth + 1);
			}
			dfs(total + x, depth + 1);
			arr[num]++;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n.length(); i++) {
		v.insert(n[i]);
		arr[n[i] - '0']++;
	}
	string total = "";
	dfs(total, 0);
	cout << answer;

}