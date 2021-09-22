#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include<unordered_map>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string cs, s;
	while (cin>>cs>>s) {
		
		int cnt = 0;
		
		for (int i = 0; i < s.length(); i++) {
			if (cs[cnt] == s[i])cnt++;
			if (cnt == cs.length())break;
		}		

		if (cnt == cs.length()) cout << "Yes" << '\n';
		else cout << "No" << '\n';
		
	}
}


