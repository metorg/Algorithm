#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

long long n, k;
int ar[1001];
int cnt = 0;
void aratos() {

	for (int i = 2; i <= n; i++) {
		if (!ar[i]) {
			for (int j = i; j <= n; j += i) {
				if (ar[j] == 1)continue;
				ar[j] = 1;
				cnt++;
				if (cnt == k) {
					cout << j;
					return;
				}
			}
		}
	}
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	aratos();

}