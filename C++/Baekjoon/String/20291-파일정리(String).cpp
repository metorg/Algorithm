#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include<unordered_map>
#include<map>
#include<set>

using namespace std;

int n;
map<string, int> m;
string s;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	while (n--) {

		cin >> s;
		string tmp="";

		for (int i = s.length() - 1; i >= 0; i--) {
			if (s[i] == '.') {
				tmp = s.substr(i+1, s.length() - i);
				m[tmp]++;
				break;
			}
		}
	}

	for (auto it : m)cout << it.first<<' '<<m[it.first]<<'\n';

}

