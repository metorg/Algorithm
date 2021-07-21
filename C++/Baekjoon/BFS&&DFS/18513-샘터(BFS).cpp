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

unordered_map<int, int > um;
queue<pair<int,int>> q;

int n, k,pool;
int mov[2] = { -1,1 };

long long bfs() {

	long long answer = 0;
	while (!q.empty()) {
		
		int current = q.front().first;
		int dist = q.front().second;
		q.pop();

		for (int i = 0; i < 2; i++) {
			int next = current + mov[i];
			if (um[next])continue;
			q.push({ next,dist + 1 });
			answer += dist+1;
			um[next]++;
			k--;
			if (k == 0)return answer;
		}
	}
	return answer;
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> pool;
		um[pool]++;
		q.push({ pool,0 });
	}
	cout << bfs();

}