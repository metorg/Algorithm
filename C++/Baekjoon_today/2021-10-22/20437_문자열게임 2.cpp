#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int total;
string s;
int cnt;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> total;
	while (total--) {
		
		int visit[26] = {};
		queue<int> q[26] = {};
		int answer_max = 0;
		int answer_min = 10001;

		cin >> s >> cnt;
		
		for (int i = 0; i < s.length(); i++) {
			
			int tmp = s[i] - 'a';
			visit[tmp]++;
			q[tmp].push(i);

			if (visit[tmp] >= cnt) {
				answer_max = max(answer_max, i - q[tmp].front());
				answer_min = min(answer_min, i - q[tmp].front());
				q[tmp].pop();
			}
		}

		if (answer_max == 0 && answer_min == 10001) 
			cout << -1 << '\n';
		else 
			cout << answer_min+1 << ' ' << answer_max+1 << '\n';
		
	}

}