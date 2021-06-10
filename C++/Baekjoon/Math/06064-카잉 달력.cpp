#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include<set>

using namespace std;

int num,cnt;
int last = 2000000000;
int n, m, cn, cm;
int check;
int main() {
	cin >> num;
	for (int i = 0;i < num;i++) {
		cin >> n >> m >> cn >> cm;
		if (cn == cm) {
			cout << cn << '\n';
			continue;
		}
		
			int flag = 0;
		for (check = cn;check<=n*m;check += n) {
			if (check % m == cm) {
				flag = 1;
				cout << check << '\n';
				break;
			}
			if (check % m == 0&&cm==m) {
				cout << check << '\n';
				flag = 1;
				break;
			}
			
		}
		if (flag == 0)cout << -1 << '\n';

	}
}
