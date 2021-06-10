#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include<stdio.h>
#include<string.h>
#include<cstdio>
#include<set>

using namespace std;

int n, k;
int	limit = 2e9;
int answer = 0;
int visit[100003];

void bfs() {
	
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,n });
	
	while (!pq.empty()) {
		
		int cnt = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		
		visit[cur] = 1;
		
		if (limit < cnt)continue;

		if (cur == k && limit >= cnt) {
			limit = cnt;
			answer++;
		}
		if (cur * 2 <= 100001&&visit[cur*2]==0)pq.push({ -(cnt + 1),cur * 2 });
		if (cur +1 <= 100001&&visit[cur+1]==0)pq.push({ -(cnt + 1),cur + 1 });
		if (cur -1 <= 100001&&visit[cur-1]==0)pq.push({ -(cnt + 1),cur - 1 });
	}

}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	bfs();
	cout << limit << '\n' << answer;
}

