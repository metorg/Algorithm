#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
#include<cstring>
#include<stack>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	stack<pair<int,int>> s;
	int n,num;

	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> num;		
		while (!s.empty()) {
			if (s.top().first < num) {
				s.pop();
			}
			else {
				cout << s.top().second << ' ';
				s.push({ num,i});
				break;
			}
		}
		
		if (s.empty()) {
			cout << 0 << ' ';
			s.push({ num,i});
		}		
	}
}