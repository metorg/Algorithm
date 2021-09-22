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
	
	string k, s;
	string answer="";

	cin >> k>> s;
	for (int i = 0; i < k.length(); i++) {
		if ('0' <= k[i] && k[i] <= '9') continue;
		else answer += k[i];		
	}
	
	if (answer.find(s)==string::npos)cout << 0;
	else cout << 1;
}


