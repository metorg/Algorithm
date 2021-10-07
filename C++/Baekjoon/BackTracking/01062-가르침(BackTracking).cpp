#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#include<unordered_map>
using namespace std;
unordered_map<int,int> visited;
set<char> arr[51];
int n = 0, k = 0, result = 0;

void dfs(int alpha, int cnt) {
	if (cnt == (k - 5)) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			bool jud = true;

			for (auto it = arr[i].begin(); it != arr[i].end(); it++) {
				if (visited[*it - 'a'] == 0) {
					jud = false;
					break;
				}
			}
			
			if (jud == true)
				cnt++;
		}
		 result = max(result,cnt);

		return;
	}

	for (int i = alpha; i < 26; i++) {

		if (visited[i] == 0) {
			visited[i] = 1;
			dfs(i,cnt + 1);
			visited[i] = 0; 
		}
	}

}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	visited['a' - 'a'] = 1;
	visited['c' - 'a'] = 1;
	visited['i' - 'a'] = 1;
	visited['t' - 'a'] = 1;
	visited['n' - 'a'] = 1;

	for (int i = 0; i < n; i++) {
		string v;
		cin >> v;
		for (int j = 0; j < v.size(); j++) {
			if (v[j] != 'a' && v[j] != 'c' && v[j] != 'i' && v[j] != 't' && v[j] != 'n') {
				arr[i].insert(v[j]);
			}
		}
			
	}
	

	if (k < 5) {
		cout << 0 << '\n';
		return 0;
	}
	else if (k == 26) {
		cout << n << '\n';
		return 0;
	}
	dfs(0,0);

	cout << result << '\n';
}