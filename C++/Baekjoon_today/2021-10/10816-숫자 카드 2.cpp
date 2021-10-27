#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

unordered_map<int, int> um;
int n, m,num;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	while (n--) {
		cin >> num;
		um[num]++;
	}
	cin >> m;
	while (m--) {
		cin >> num;
		cout << um[num] << ' ';
	}
}