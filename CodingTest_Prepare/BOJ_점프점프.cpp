#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int visit[100001];
int stone[100001];
int n, s;
int answer = 0;

void dfs(int start) {
    
	if (start < 0 || start >= n)return;
	if (visit[start])return;
	visit[start] = 1;
	answer++;
	dfs(start + stone[start]);
	dfs(start - stone[start]);

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> stone[i];
	}
	cin >> s;
	dfs(s-1);
	cout << answer;
	
}
