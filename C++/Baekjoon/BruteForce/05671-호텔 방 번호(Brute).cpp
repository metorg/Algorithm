#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <set>

using namespace std;

int visit[10];
int start, finish;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {

		int cnt = 0;
		cin >> start >> finish;
		if (cin.eof() == true) break;

		for (int i = start; i <= finish; i++) {
			
			memset(visit, 0, sizeof(visit));
			int tmp = i;

			while (tmp) {
				visit[tmp % 10]++;
				if (visit[tmp % 10] == 2) {
					cnt++;					
					break;
				}
				tmp /= 10;
			}
		}
		cout << finish - start - cnt + 1 << '\n';
	}

}