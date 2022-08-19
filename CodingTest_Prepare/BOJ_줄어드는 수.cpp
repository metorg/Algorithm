#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

long long answer=-1;
int cnt = 10;
int n;

void bfs() {
	
	queue<long long> q;
	for (int i = 1; i <10; i++) q.push(i);
	while (!q.empty()) {
		long long cur = q.front();
		q.pop();
		for (int i = 0; i < 10; i++) {
			if (cur % 10 <= i)break;
			cnt++;
			if (cnt == n) {
				answer = cur * 10 + i;
				return;
			}
			q.push((cur * 10) + i);
		}
	}
	return;

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	bfs();

	if (n <= 10) cout << n-1;
	else cout << answer;
	
}
