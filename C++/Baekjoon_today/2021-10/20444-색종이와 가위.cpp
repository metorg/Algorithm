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
long long answer=0;
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	long long left = 0;
	long long right = n/2;
	while (left <= right) {
		long long mid = (left + right) / 2;
		if (((n-mid+1) * (mid + 1)) > k) {
			right = mid-1;
		}
		else if (((n - mid + 1) * (mid + 1)) == k) {
			answer = 1;
			break;
		}
		else
			left = mid+1;
	}


	if (answer == 1)cout << "YES";
	else cout << "NO";


}