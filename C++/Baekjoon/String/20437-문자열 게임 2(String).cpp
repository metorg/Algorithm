#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;

int total_n,n;
string s;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> total_n;
	while (total_n--) {
		map<char, vector<int>> m;
		
		int answer_min = 1e9;
		int answer_max = -1;
		
		cin >> s;
		cin >> n;
		
		for (int i = 0; i < s.length(); i++) {
			m[s[i]].push_back(i);
			if (m[s[i]].size() >= n) {
				answer_min = min(answer_min, i - m[s[i]][m[s[i]].size()-n]);
				answer_max = max(answer_max, i - m[s[i]][m[s[i]].size()-n]);
			}
		}

		if (answer_min == 1e9) {
			cout << -1 << '\n';
		}
		else {
			cout << answer_min+1 << ' ' << answer_max+1 << '\n';
		}
	}

}



