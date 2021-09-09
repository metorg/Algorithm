#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <set>

using namespace std;

int n, start, power;
int answer = 0;
int num, num2;

vector<int> v[100001];
int tl[100001];

int dfs(int cur,int dist) {
	
	int max_dist = 0;
	for (auto nxt : v[cur]) {
		if (nxt != dist) {
			max_dist = max(max_dist, dfs(nxt, cur) + 1);
			}
	}
	tl[cur] = max_dist;
	return tl[cur];
	
}

void search(int cur, int dist) {

	for (auto nxt : v[cur]) {
		if (nxt != dist) {
			if (tl[nxt] >= power) {
				answer += 1;
				search(nxt, cur);
			}
		}
	}
}


int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> start >> power;
	for (int i = 0; i < n - 1; i++) {
		cin >> num >> num2;
		v[num].push_back(num2);
		v[num2].push_back(num);
	}
	
	dfs(start,0);
	search(start, 0);

	cout << answer * 2;
	
}