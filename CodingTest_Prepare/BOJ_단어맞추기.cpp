#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
string str;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> str;
		if(!next_permutation(str.begin(), str.end()))prev_permutation(str.begin(),str.end());
		cout << str<<'\n';
	}

}
