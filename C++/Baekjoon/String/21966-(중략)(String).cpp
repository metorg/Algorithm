#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
#include<stack>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	char c;
	int cnt = 0;
	vector<char> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		v.push_back(c);
	}
	if (n <= 25) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
		}
	}
	else {
		for (int i = 12; i < n - 11; i++) {
			if (v[i-1] == '.')cnt++;
		}

		if (cnt < 1) {
			for (int i = 0; i < 11; i++) cout << v[i];
			for (int i = 0; i < 3; i++) cout << '.';
			for (int i = n - 11; i <n; i++) cout << v[i];		
		}
		else {
			for (int i = 0; i < 9; i++) cout << v[i];
			for (int i = 0; i < 6; i++) cout<<'.';
			for (int i = n - 10; i < n; i++)cout << v[i];
		}
	}
	
	
	
}