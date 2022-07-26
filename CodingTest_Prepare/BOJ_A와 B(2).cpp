#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string S, T;
int answer = 0;

void recursion(string s, string t) {
	if (s.length() > t.length())return;
	if (s == t) {
		answer = 1;
		return;
	}

	if (t[0] == 'A' && t[t.length() - 1] == 'A') {
		t.pop_back();
		recursion(s, t);
	}

	else if (t[0] == 'B' && t[t.length() - 1] == 'A') {
		string tmp = t;
		reverse(tmp.begin(), tmp.end());
		tmp.pop_back();
		recursion(s, tmp);
		t.pop_back();
		recursion(s, t);
	}

	else if (t[0] == 'B' && t[t.length() - 1] == 'B') {
		reverse(t.begin(), t.end());
		t.pop_back();
		recursion(s, t);
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> S >> T;

	recursion(S, T);
	cout << answer;
}
