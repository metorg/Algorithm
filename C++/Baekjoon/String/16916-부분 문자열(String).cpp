#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;

vector<int> pi;

void getPi(string p) {

	int j = 0;
	pi.resize(p.size(), 0);
	
	for (int i = 1; i < p.length(); i++) {
		while ((j > 0) && (p[i] != p[j]))
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
}

int kmp(string s, string p) {
	
	int answer = 0;
	getPi(p);
	int j = 0;
	for (int i = 0; i < s.length(); i++) {
		while (j > 0 && s[i] != p[j]) {
			j = pi[j - 1];
		}
		if (s[i] == p[j]) {
			if (j == p.length() - 1) {
				answer = 1;
				break;
			}
			else {
				j++;
			}
		}
	}
	return answer;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s, p;

	cin >> s >> p;
	
	cout << kmp(s, p);

}