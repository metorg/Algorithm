#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include<unordered_map>
#include<set>

using namespace std;

int total_string;
char t[4] = { 'A','F','C'};
string st;
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> total_string;

	while (total_string--) {
		cin >> st;
		st.erase(unique(st.begin(), st.end()), st.end());
		
		int cnt = 0;
		int last = 0;
		if ('A' <= st[0] && st[0] <= 'F') {
			if (st[0] == 'A') {
				cnt++;
			}
		}
		else if ('A' <= st[st.length() - 1] && st[st.length() - 1] <= 'F') {
			if (st[st.length() - 1] == 'C') {
				last++;
			}
		}
		else {
			cout << "Good" << '\n';
			continue;
		}
		for (int i = 1; i <= st.length() - last; i++) {
			if (st[i] == t[cnt])cnt++;
			else {
				cout << "Good" << '\n';
				last = 100;
				break;
			}
		}
		if (last == 100)continue;
		else cout << "Infected!" << '\n';
			
	}
}

