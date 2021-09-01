#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include<set>

using namespace std;

string s;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {

		int cnt = 0;
		int con = 0;
		int coll = 0;
		char before = NULL;
		int answer = 0;
		
		cin >> s;
		
		if (s == "end")return 0;
		
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
				coll++;
				con = 0;
				cnt++;
			}
			else {
				coll = 0;
				con++;
			}
			if (coll == 3 || con == 3) {
				answer = 1;
				break;
			}
			if (before == s[i]) {
				if (before == 'e' || before == 'o') {}
				else {
					answer = 1;
					break;
				}
			}
			before = s[i];
		}

		if (cnt < 1)answer = 1;
		if (answer)
			cout << "<" << s <<"> is not acceptable." << '\n';
		else
			cout << "<" << s << "> is acceptable." << '\n';
	}
}

